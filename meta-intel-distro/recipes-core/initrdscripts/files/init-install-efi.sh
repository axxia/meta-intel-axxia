#!/bin/sh -e
#
# Copyright (c) 2012, Intel Corporation.
# All rights reserved.
#
# install.sh [device_name] [rootfs_name]
#
# Customized for multiple kernels by Intel Axxia team

PATH=/sbin:/bin:/usr/sbin:/usr/bin

# figure out how big of a boot partition we need
boot_size=$(du -ms /run/media/$1/ | awk '{print $1}')
# remove rootfs.img ($2) from the size if it exists, as its not installed to /boot
if [ -e /run/media/$1/$2 ]; then
    boot_size=$(( boot_size - $( du -ms /run/media/$1/$2 | awk '{print $1}') ))
fi
# remove initrd from size since its not currently installed
if [ -e /run/media/$1/initrd ]; then
    boot_size=$(( boot_size - $( du -ms /run/media/$1/initrd | awk '{print $1}') ))
fi
# add 10M to provide some extra space for users and account
# for rounding in the above subtractions
boot_size=$(( boot_size + 10 ))

# 5% for swap
swap_ratio=5

# Get a list of hard drives
hdnamelist=""
live_dev_name=`cat /proc/mounts | grep ${1%/} | awk '{print $1}'`
live_dev_name=${live_dev_name#\/dev/}
# Only strip the digit identifier if the device is not an mmc
case $live_dev_name in
    mmcblk*)
    ;;
    nvme*)
    ;;
    *)
        live_dev_name=${live_dev_name%%[0-9]*}
    ;;
esac

echo "Searching for hard drives ..."

# Some eMMC devices have special sub devices such as mmcblk0boot0 etc
# we're currently only interested in the root device so pick them wisely
devices=`ls /sys/block/ | grep -v mmcblk` || true
mmc_devices=`ls /sys/block/ | grep "mmcblk[0-9]\{1,\}$"` || true
devices="$devices $mmc_devices"

for device in $devices; do
    case $device in
        loop*)
            # skip loop device
            ;;
        sr*)
            # skip CDROM device
            ;;
        ram*)
            # skip ram device
            ;;
        *)
            # skip the device LiveOS is on
            # Add valid hard drive name to the list
            case $device in
                $live_dev_name*)
                # skip the device we are running from
                ;;
                *)
                    hdnamelist="$hdnamelist $device"
                ;;
            esac
            ;;
    esac
done

if [ -z "${hdnamelist}" ]; then
    echo "You need another device (besides the live device /dev/${live_dev_name}) to install the image. Installation aborted."
    exit 1
fi

TARGET_DEVICE_NAME=""
for hdname in $hdnamelist; do
    # Display found hard drives and their basic info
    echo "-------------------------------"
    echo /dev/$hdname
    if [ -r /sys/block/$hdname/device/vendor ]; then
        echo -n "VENDOR="
        cat /sys/block/$hdname/device/vendor
    fi
    if [ -r /sys/block/$hdname/device/model ]; then
        echo -n "MODEL="
        cat /sys/block/$hdname/device/model
    fi
    if [ -r /sys/block/$hdname/device/uevent ]; then
        echo -n "UEVENT="
        cat /sys/block/$hdname/device/uevent
    fi
    echo
done

# Get user choice
while true; do
    echo "Please select an install target or press n to exit ($hdnamelist ): "
    read answer
    if [ "$answer" = "n" ]; then
        echo "Installation manually aborted."
        exit 1
    fi
    for hdname in $hdnamelist; do
        if [ "$answer" = "$hdname" ]; then
            TARGET_DEVICE_NAME=$answer
            break
        fi
    done
    if [ -n "$TARGET_DEVICE_NAME" ]; then
        break
    fi
done

if [ -n "$TARGET_DEVICE_NAME" ]; then
    echo "Installing image on /dev/$TARGET_DEVICE_NAME ..."
else
    echo "No hard drive selected. Installation aborted."
    exit 1
fi

device=/dev/$TARGET_DEVICE_NAME

#
# The udev automounter can cause pain here, kill it
#
rm -f /etc/udev/rules.d/automount.rules
rm -f /etc/udev/scripts/mount*

#
# Unmount anything the automounter had mounted
#
umount ${device}* 2> /dev/null || /bin/true

mkdir -p /tmp

# Create /etc/mtab if not present
if [ ! -e /etc/mtab ] && [ -e /proc/mounts ]; then
    ln -sf /proc/mounts /etc/mtab
fi

disk_size=$(parted ${device} unit mb print | grep '^Disk .*: .*MB' | cut -d" " -f 3 | sed -e "s/MB//")

swap_size=$((disk_size*swap_ratio/100))
rootfs_size=$((disk_size-boot_size-swap_size))

rootfs_start=$((boot_size))
rootfs_end=$((rootfs_start+rootfs_size))
swap_start=$((rootfs_end))

# MMC devices are special in a couple of ways
# 1) they use a partition prefix character 'p'
# 2) they are detected asynchronously (need rootwait)
rootwait=""
part_prefix=""
if [ ! "${device#/dev/mmcblk}" = "${device}" ] || \
   [ ! "${device#/dev/nvme}" = "${device}" ]; then
    part_prefix="p"
    rootwait="rootwait"
fi

# USB devices also require rootwait
if [ -n `readlink /dev/disk/by-id/usb* | grep $TARGET_DEVICE_NAME` ]; then
    rootwait="rootwait"
fi

bootfs=${device}${part_prefix}1
rootfs=${device}${part_prefix}2
swap=${device}${part_prefix}3

echo "*****************"
echo "Boot partition size:   $boot_size MB ($bootfs)"
echo "Rootfs partition size: $rootfs_size MB ($rootfs)"
echo "Swap partition size:   $swap_size MB ($swap)"
echo "*****************"
echo "Deleting partition table on ${device} ..."
dd if=/dev/zero of=${device} bs=512 count=35

echo "Creating new partition table on ${device} ..."
parted ${device} mklabel gpt

echo "Creating boot partition on $bootfs"
parted ${device} mkpart boot fat32 0% $boot_size
parted ${device} set 1 boot on

echo "Creating rootfs partition on $rootfs"
parted ${device} mkpart root ext4 $rootfs_start $rootfs_end

echo "Creating swap partition on $swap"
parted ${device} mkpart swap linux-swap $swap_start 100%

parted ${device} print

echo "Waiting for device nodes..."
C=0
while [ $C -ne 3 ] && [ ! -e $bootfs  -o ! -e $rootfs -o ! -e $swap ]; do
    C=$(( C + 1 ))
    sleep 1
done

echo "Formatting $bootfs to vfat..."
mkfs.vfat $bootfs

echo "Formatting $rootfs to ext4..."
mkfs.ext4 $rootfs

echo "Formatting swap partition...($swap)"
mkswap $swap

mkdir /tgt_root
mkdir /src_root
mkdir -p /boot

# Handling of the target root partition
mount $rootfs /tgt_root
mount -o rw,loop,noatime,nodiratime /run/media/$1/$2 /src_root
echo "Copying rootfs files..."
cp -a /src_root/* /tgt_root
if [ -d /tgt_root/etc/ ] ; then
    boot_uuid=$(blkid -o value -s UUID ${bootfs})
    swap_part_uuid=$(blkid -o value -s PARTUUID ${swap})
    echo "/dev/disk/by-partuuid/$swap_part_uuid                swap             swap       defaults              0  0" >> /tgt_root/etc/fstab
    echo "UUID=$boot_uuid              /boot            vfat       defaults              1  2" >> /tgt_root/etc/fstab
    # We dont want udev to mount our root device while we're booting...
    if [ -d /tgt_root/etc/udev/ ] ; then
        echo "${device}" >> /tgt_root/etc/udev/mount.ignorelist
    fi
fi

# Handling of the target boot partition
mount $bootfs /boot
echo "Preparing boot partition..."

EFIDIR="/boot/EFI/BOOT"
mkdir -p $EFIDIR
# Copy the efi loader
cp /run/media/$1/EFI/BOOT/*.efi $EFIDIR

echo "Looking for kernels to use as boot target.."
# Find kernel to boot to
# Give user options if multiple are found

kernels="$(find /src_root/boot -type f  \
           -name bzImage* -o -name zImage* \
           -o -name vmlinux* -o -name vmlinuz* \
           -o -name fitImage* | sed s:.*/::)"

if [ -n "$(echo $kernels)" ]; then
    # Copy kernel artifacts in boot partition
    for k in $kernels; do
        cp /src_root/boot/$k /boot
    done

    # only one kernel entry if no space
    if [ -z "$(echo $kernels | grep ' ')" ]; then
        kernel=$kernels
        echo "$kernel will be used as the boot target"
    else
        # Check for default kernel (symlink for bzImage)
        defkernel="$(readlink /src_root/boot/bzImage)"
        if [ -z "$defkernel" ]; then
	    # If no default kernel found, get user choice
            while true; do
               echo -e "\nWhich kernel do we want to boot by default? Available kernels:"
               echo $kernels
               read answer
               for k in $kernels; do
                   if [ "$answer" = "$k" ]; then
                       kernel=$answer
                       break
                  fi
               done
               if [ -n "$kernel" ]; then
	           break
               fi
            done
        else
	    # If default kernel is found, get user choice about using it
            while true; do
                echo -e "\nPress y if you want to use $defkernel as default kernel or choose another available kernel:"
                echo $kernels
                read answer
		if [ "$answer" = "y" ]; then
		    kernel=$defkernel
		    break
		fi
                for k in $kernels; do
                    if [ "$answer" = "$k" ]; then
		        kernel=$answer
                        break
                    fi
                done
		if [ -n "$kernel" ]; then
		    break
                fi
            done
        fi
    fi
else
    echo "No kernels found, exiting..."
    exit 1
fi

# Customize boot options (grub or systemd-boot)

if [ -f /run/media/$1/EFI/BOOT/grub.cfg ]; then
    root_part_uuid=$(blkid -o value -s PARTUUID ${rootfs})
    GRUBCFG="$EFIDIR/grub.cfg"
    cp /run/media/$1/EFI/BOOT/grub.cfg $GRUBCFG
    # Update grub config for the installed image
    # Delete the install entry
    sed -i "/menuentry 'install'/,/^}/d" $GRUBCFG
    # Delete the initrd lines
    sed -i "/initrd /d" $GRUBCFG
    # Delete any LABEL= strings
    sed -i "s/ LABEL=[^ ]*/ /" $GRUBCFG
    # Replace root= and add additional standard boot options
    # We use root as a sentinel value, as vmlinuz is no longer guaranteed
    sed -i "s/ root=[^ ]*/ root=PARTUUID=$root_part_uuid rw $rootwait quiet /g" $GRUBCFG
    # Replace bzImage name with the kernel found in rootfs /boot
    line="$(grep -m 1 'linux /bzImage' $GRUBCFG)"
    sed -i "s/menuentry 'boot'/menuentry 'boot $kernel'/g" $GRUBCFG
    sed -i "s/linux \/bzImage/linux \/$kernel/g" $GRUBCFG
    # only one kernel entry if no space
    if [ -n "$(echo $kernels | grep " ")" ]; then
        for k in $(echo $kernels | sed "s#$kernel##g"); do
            echo -e "\nmenuentry 'boot $k'{" >> $GRUBCFG
            echo $line | sed "s/linux \/bzImage/linux \/$k/g" >> $GRUBCFG
            echo "}" >> $GRUBCFG
        done
    fi
fi

if [ -d /run/media/$1/loader ]; then
    rootuuid=$(blkid -o value -s PARTUUID ${rootfs})
    SYSTEMDBOOT_CFGS="/boot/loader/entries/*.conf"
    # copy config files for systemd-boot
    cp -dr /run/media/$1/loader /boot
    # delete the install entry
    rm -f /boot/loader/entries/install.conf
    # delete the initrd lines
    sed -i "/initrd /d" $SYSTEMDBOOT_CFGS
    # delete any LABEL= strings
    sed -i "s/ LABEL=[^ ]*/ /" $SYSTEMDBOOT_CFGS
    # delete any root= strings
    sed -i "s/ root=[^ ]*/ /" $SYSTEMDBOOT_CFGS
    # add the root= and other standard boot options
    sed -i "s@options *@options root=PARTUUID=$rootuuid rw $rootwait quiet @" $SYSTEMDBOOT_CFGS
    # only one kernel entry if no space
    if [ -n "$(echo $kernels | grep " ")" ]; then
        if [ -f "/boot/loader/entries/boot.conf" ]; then
            for k in $(echo $kernels | sed "s#$kernel##g"); do
                cp /boot/loader/entries/boot.conf /boot/loader/entries/boot-$k.conf
                # For each alternative kernel
                sed -i "s/title boot/title boot $kernel/g" /boot/loader/entries/boot-$k.conf
                sed -i "s/linux \/bzImage/linux \/$k/g" /boot/loader/entries/boot-$k.conf
            done
        # For default kernel
        sed -i "s/title boot/title boot $kernel/g" /boot/loader/entries/boot.conf
        sed -i "s/linux \/bzImage/linux \/$kernel/g" /boot/loader/entries/boot.conf
        fi
    fi
fi

# copy any extra files needed for ESP
if [ -d /run/media/$1/esp ]; then
    cp -r /run/media/$1/esp/* /boot
fi

umount /src_root
umount /tgt_root
umount /boot

sync

echo "Installation successful. Remove your installation media and press ENTER to reboot."

read enter

echo "Rebooting..."
reboot -f
