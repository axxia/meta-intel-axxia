do_install:append () {
# Create external-modules-setup script
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
    make clean oldconfig scripts tools/objtool modules_prepare
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
