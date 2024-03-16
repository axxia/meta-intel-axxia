DEPENDS:append = " virtual/${TARGET_PREFIX}gcc bc-native bison-native rsync-native"

IMAGE_INSTALL:append = " kernel-devsrc"

EXTRA_OEMAKE:append = ' CC="${KERNEL_CC}"'
EXTRA_OEMAKE:append = ' HOSTCFLAGS="${BUILD_CFLAGS}" HOSTLDFLAGS="${BUILD_LDFLAGS}"'

ROOTFS_POSTPROCESS_COMMAND:append = " external_modules_setup "

external_modules_setup () {
    oe_runmake -C ${IMAGE_ROOTFS}/usr/src/kernel headers_install \
        INSTALL_HDR_PATH=${IMAGE_ROOTFS}/usr

    for kernel in ${IMAGE_ROOTFS}/lib/modules/*; do
        [ ! -x $kernel ] && continue
        cd $kernel/build
        oe_runmake clean olddefconfig scripts tools/objtool modules_prepare
        cd -
    done
}
