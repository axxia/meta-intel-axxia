do_install:append () {
### Create external-modules-setup script
cat << 'EOF' > ${D}${SDKPATH}/external-modules-setup.sh
#!/bin/sh

RED='\033[0;31m'
NC='\033[0m'

if [ -z "$SDKTARGETSYSROOT" ]; then
    echo "${RED}Error: There is no SDK setup. Please source top-level SDK environment script first.${NC}" >&2
    exit 1
else
    make -C $SDKTARGETSYSROOT/usr/src/kernel headers_install INSTALL_HDR_PATH=$SDKTARGETSYSROOT/usr
    status=$?
    if [ $status -ne 0 ]; then
        echo "${RED}Error: Installing UAPI headers in SYSROOT fails with status $status.${NC}" >&2
        exit $status
    fi
fi

for kernel in $SDKTARGETSYSROOT/lib/modules/*; do
    if [ ! -x $kernel ]; then
        continue
    fi
    cd $kernel/build
    make clean olddefconfig scripts tools/objtool modules_prepare
    status=$?
    if [ $status -ne 0 ]; then
        echo "${RED}Error: External modules setup fails for kernel $(basename $kernel) with status $status.${NC}" >&2
        exit $status
    fi
    cd -
done
EOF

chmod 0755 ${D}${SDKPATH}/external-modules-setup.sh

### Mark the target and native system dirs as such, so pkgconf strips them
# from --cflags/--libs the way pkg-config did. pkgconf prefixes the sysroot
# onto a fragment before matching it against this list, so the list must be
# sysroot-prefixed too, or -I$SDKTARGETSYSROOT/usr/include leaks out of every
# target .pc file and breaks -Werror host tool builds such as objtool.
# SDK-side counterpart of oe-core a3320989ca. Both target and native dirs are
# needed: setting the variable replaces pkgconf's built-in list, it does not
# extend it.
cat >> ${D}${SDKPATH}/environment-setup-${REAL_MULTIMACH_TARGET_SYS} << EOF

export PKG_CONFIG_SYSTEM_INCLUDE_PATH="\$SDKTARGETSYSROOT${target_includedir}:\$OECORE_NATIVE_SYSROOT${includedir_nativesdk}"
export PKG_CONFIG_SYSTEM_LIBRARY_PATH="\$SDKTARGETSYSROOT${target_libdir}:\$SDKTARGETSYSROOT${target_base_libdir}:\$OECORE_NATIVE_SYSROOT${libdir_nativesdk}"
EOF
}
