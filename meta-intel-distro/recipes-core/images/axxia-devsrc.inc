DEPENDS_append = " virtual/${TARGET_PREFIX}gcc bc-native bison-native rsync-native patchelf-native"

IMAGE_INSTALL_append = " kernel-devsrc"

inherit linuxloader

EXTRA_OEMAKE_append = ' CC="${KERNEL_CC}"'
EXTRA_OEMAKE_append = ' HOSTCFLAGS="${BUILD_CFLAGS}" HOSTLDFLAGS="${BUILD_LDFLAGS}"'

ROOTFS_POSTPROCESS_COMMAND_append = " external_modules_setup; "

external_modules_setup () {
    oe_runmake -C ${IMAGE_ROOTFS}/usr/src/kernel headers_install \
        INSTALL_HDR_PATH=${IMAGE_ROOTFS}/usr

    dynamic_loader=${@get_linuxloader(d)}
    for kernel in ${IMAGE_ROOTFS}/lib/modules/*; do
        [ ! -x $kernel ] && continue
        cd $kernel/build
        oe_runmake clean olddefconfig scripts tools/objtool modules_prepare
        for bin in $(find ! -path '*/scripts/atomic/*' -type f -executable -exec sh -c 'test "$(head -c 2 "$1")" != "#!"' sh {} \; -print); do
            patchelf --set-interpreter $dynamic_loader $bin
        done
        cd -
    done
}
