DEPENDS:remove = "grub-efi"

inherit uefi-comboapp

EFI_PROVIDER = "systemd-boot"
IMAGE_FSTYPES = "wic ext4"
WKS_FILE = "generic-bootdisk.wks.in"

DISK_SIGNATURE_UUID ??= "deadbeef-dead-beef-dead-beefdeadbeef"

do_uefiapp_deploy:append() {
    for i in ${DEPLOY_DIR_IMAGE}/${IMAGE_LINK_NAME}.boot*.efi; do
        target=`basename $i`
        target=`echo $target | sed -e 's/${IMAGE_LINK_NAME}.//'`

        cat > ${IMAGE_ROOTFS}/boot/startup.nsh << EOF
$target
reset
EOF
    break
    done
}
