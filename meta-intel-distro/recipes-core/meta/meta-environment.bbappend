do_install:append () {
### Ship a make wrapper in the SDK so kernel host-tool builds (objtool,
# etc.) don't inherit target PKG_CONFIG_SYSROOT_DIR/PATH. Real make is
# resolved once at source time via _HOSTMAKE_REAL, not per-invocation.
install -d ${D}${SDKPATH}/sysroots/${SDK_SYS}/usr/bin/hostmake-wrapper

cat > ${D}${SDKPATH}/sysroots/${SDK_SYS}/usr/bin/hostmake-wrapper/make << 'WRAPPER'
#!/bin/sh
# Kernel host tools set HOSTPKG_CONFIG with plain '=', which beats an
# exported env var, so this wrapper injects it via the make command line
# instead. Strips PKG_CONFIG_SYSROOT_DIR/PATH only for those pkg-config
# lookups; app builds via configure/cmake/meson still see them exported.
if [ -z "$_HOSTMAKE_REAL" ]; then
    echo "hostmake-wrapper: _HOSTMAKE_REAL not set, re-source environment-setup" >&2
    exit 127
fi
exec "$_HOSTMAKE_REAL" HOSTPKG_CONFIG='env -u PKG_CONFIG_SYSROOT_DIR -u PKG_CONFIG_PATH -u PKG_CONFIG_LIBDIR pkg-config' "$@"
WRAPPER

chmod 0755 ${D}${SDKPATH}/sysroots/${SDK_SYS}/usr/bin/hostmake-wrapper/make

cat >> ${D}${SDKPATH}/environment-setup-${REAL_MULTIMACH_TARGET_SYS} << 'WRAPPER_HOSTMAKE'

_HOSTMAKE_REAL="${_HOSTMAKE_REAL:-$(command -v make)}"
export _HOSTMAKE_REAL
export PATH="$OECORE_NATIVE_SYSROOT/usr/bin/hostmake-wrapper:$PATH"
WRAPPER_HOSTMAKE

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
}
