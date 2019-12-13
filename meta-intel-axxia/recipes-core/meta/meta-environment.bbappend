do_install_prepend () {
# Add HOST_EXTRACFLAGS export line in SDK environment-setup scripts

line='export HOST_EXTRACFLAGS="-I./tools/include \\\
-I$OECORE_NATIVE_SYSROOT/usr/include \\\
-L$OECORE_NATIVE_SYSROOT/usr/lib \\\
-L$OECORE_NATIVE_SYSROOT/lib \\\
-Wl,-rpath-link,$OECORE_NATIVE_SYSROOT/usr/lib \\\
-Wl,-rpath-link,$OECORE_NATIVE_SYSROOT/lib \\\
-Wl,-rpath,$OECORE_NATIVE_SYSROOT/usr/lib \\\
-Wl,-rpath,$OECORE_NATIVE_SYSROOT/lib \\\
-Wl,--dynamic-linker=$OECORE_NATIVE_SYSROOT/lib/ld-linux-x86-64.so.2"'

for file in $(ls ${SDK_OUTPUT}/${SDKPATH}/environment-setup-*); do
    if ! grep -q "export HOST_EXTRACFLAGS" $file; then
        eval "sed -i '/export CONFIGURE_FLAGS/a $line' $file"
    fi
done
}

do_install_append () {
# Create external-modules-setup script
cat << 'EOF' > ${D}${SDKPATH}/external-modules-setup.sh
#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'

if [ -z "$SDKTARGETSYSROOT" ]; then
    echo -e "${RED}Error: There is no SDK setup. Please source top-level SDK environment script first.${NC}" >&2
    exit 1
fi

for kernel in $SDKTARGETSYSROOT/lib/modules/*; do
    if [ ! -x $kernel ]; then
        continue
    fi
    cd $kernel/build
    make clean oldconfig scripts tools/objtool
    status=$?
    if [[ $status -ne 0 ]]; then
        echo -e "${RED}Error: External modules setup fails for kernel $(basename $kernel) with status $status.${NC}" >&2
        exit $status
    fi
    cd -
done
EOF

chmod 0755 ${D}${SDKPATH}/external-modules-setup.sh
}
