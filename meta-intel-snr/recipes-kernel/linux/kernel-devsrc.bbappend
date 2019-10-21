do_install_prepend() {
    # In kernel > 4.19.66, there were some files removed. Cheap trick to avoid error:
    # cp: cannot stat 'arch/x86/purgatory/string.c': No such file or directory
    [ "${ARCH}" = "x86" ] && touch ${S}/arch/x86/purgatory/string.c
}

do_install_append() {
    # required files from kernel sources
    (
        cd ${S}

        # required Makefile, Kbuild and *.mk files for "clean" target
        cp --parents $(find  -type f -name "Kbuild*" -o -name "*.mk") $kerneldir/build
        cp -a --parents Documentation/Makefile $kerneldir/build/

        # required files for "tools/objtool" target
        cp -a --parents tools/objtool $kerneldir/build/
        cp -a --parents tools/build/fixdep.c $kerneldir/build/
        if [ "${ARCH}" = "x86" ]; then
            cp -a --parents arch/x86/lib/inat.c $kerneldir/build/
            cp -a --parents arch/x86/lib/insn.c $kerneldir/build/
            cp -a --parents arch/x86/lib/x86-opcode-map.txt $kerneldir/build/
            cp -a --parents arch/x86/tools/gen-insn-attr-x86.awk $kerneldir/build/
        fi

        # required files for "modules_prepare" target
        cp -a --parents kernel/bounds.c $kerneldir/build/
        cp -a --parents kernel/time/timeconst.bc $kerneldir/build/
        cp -a --parents tools/lib $kerneldir/build/
        cp -a --parents tools/include $kerneldir/build/
        cp -a --parents tools/scripts/utilities.mak $kerneldir/build/
        if [ "${ARCH}" = "x86" ]; then
            cp -a --parents arch/x86/kernel/asm-offsets*.c $kerneldir/build/
        fi
    )

    # required headers for out-of-tree modules build
    (
        cd ${B}
        cp --parents $(find  -type f -name "unistd_*.h") $kerneldir/build
    )

    # enforce all scripts to use /usr/bin/awk
    (
        cd ${D}
        for i in $(grep -srI "\!/bin/awk" | cut -d":" -f1); do
            sed -i -e "s#\!/bin/awk#\!/usr/bin/env awk#g" $i
        done
    )

    # Remove string.c if empty; file was created only to avoid a copy error
    [ ! -s ${S}/arch/x86/purgatory/string.c ] && \
    rm ${S}/arch/x86/purgatory/string.c $kerneldir/build/arch/x86/purgatory/string.c

    chown -R root:root ${D}
}
