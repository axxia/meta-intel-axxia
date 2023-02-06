WKS_FILE = "axxia-bootdisk-efistub.wks.in" 
INITRD_IMAGE_LIVE = "core-image-minimal-initramfs"

IMAGE_FSTYPES = "wic ext4"
IMAGE_TYPEDEP:wic = "ext4"

ROOT_DISK_UUID ?= "deadbeef-dead-beef-dead-beefdeadbeef"

IMAGE_BOOT_FILES:append = "\
   ${KERNEL_IMAGETYPE} \
   ${INITRD_IMAGE_LIVE}-${MACHINE}.${INITRAMFS_FSTYPES};initramfs.${INITRAMFS_FSTYPES} \
   ${@bb.utils.contains('EFI_PROVIDER', 'grub-efi', 'grub-efi-bootx64.efi;EFI/BOOT/bootx64.efi', '', d)} \
   ${@bb.utils.contains('EFI_PROVIDER', 'grub-efi', '${IMAGE_ROOTFS}/boot/EFI/BOOT/grub.cfg;EFI/BOOT/grub.cfg', '', d)} \
   ${@bb.utils.contains('EFI_PROVIDER', 'systemd-boot', 'systemd-bootx64.efi;EFI/BOOT/bootx64.efi', '', d)} \
   ${@bb.utils.contains('EFI_PROVIDER', 'systemd-boot', '${IMAGE_ROOTFS}/boot/loader/loader.conf;loader/loader.conf ', '', d)} \
   ${@bb.utils.contains('EFI_PROVIDER', 'systemd-boot', '${IMAGE_ROOTFS}/boot/loader/entries/boot.conf;loader/entries/boot.conf', '', d)} \
   "

do_image_wic[depends] += "${INITRD_IMAGE_LIVE}:do_image_complete"
do_rootfs[depends] += "virtual/kernel:do_deploy ${EFI_PROVIDER}:do_deploy"

do_customize_bootconf() {
   if [ "${EFI_PROVIDER}" = "grub-efi" ]; then
      BOOTCONF="${IMAGE_ROOTFS}/boot/EFI/BOOT/grub.cfg"
   elif [ "${EFI_PROVIDER}" = "systemd-boot" ]; then
      BOOTCONF="${IMAGE_ROOTFS}/boot/loader/entries/boot.conf"
   fi
   sed -i '/^initrd/d' ${BOOTCONF}
   sed -i '/^linux.*/a initrd /initramfs.${INITRAMFS_FSTYPES}' ${BOOTCONF}
   sed -E -i 's/root=+[^[:space:]]+[^[:space:]]/root=PARTUUID=${ROOT_DISK_UUID}/' ${BOOTCONF}
}
addtask do_customize_bootconf after do_image before do_image_wic
