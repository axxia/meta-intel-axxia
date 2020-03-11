DEPENDS += "${ALTERNATIVE_KERNELS}"

do_install() {
    kerneldir=${D}${KERNEL_BUILD_ROOT}$KERNEL_VERSION
    install -d $kerneldir

    # For alternative kernels, use bash variables
    [ -z "$S" ] && S=${S}
    [ -z "$B" ] && B=${B}

    # create the directory structure
    rm -rf $kerneldir/build
    rm -rf $kerneldir/source
    mkdir -p $kerneldir/build

    # for compatibility with some older variants of this package, we
    # create  a /usr/src/kernel symlink to /lib/modules/<version>/source
    # only for virtual/kernel; not for alternative kernels
    mkdir -p ${D}/usr/src
    (
        if [ "$S" = "${STAGING_KERNEL_DIR}" ]; then
            cd ${D}/usr/src
            lnr ${D}${KERNEL_BUILD_ROOT}${KERNEL_VERSION}/source kernel
        fi
    )

    # for on target purposes, we unify build and source
    (
	cd $kerneldir
	ln -s build source
    )

    # first copy everything
    (
	cd $S
	cp --parents $(find  -type f -name "Makefile*" -o -name "Kconfig*") $kerneldir/build
	cp --parents $(find  -type f -name "Build" -o -name "Build.include") $kerneldir/build
    )

    # then drop all but the needed Makefiles/Kconfig files
    rm -rf $kerneldir/build/scripts
    rm -rf $kerneldir/build/include

    # now copy in parts from the build that we'll need later
    (
	cd $B

	cp Module.symvers $kerneldir/build
	cp System.map* $kerneldir/build
	if [ -s Module.markers ]; then
	    cp Module.markers $kerneldir/build
	fi

	cp -a .config $kerneldir/build

	# This scripts copy blow up QA, so for now, we require a more
	# complex 'make scripts' to restore these, versus copying them
	# here. Left as a reference to indicate that we know the scripts must
	# be dealt with.
	# cp -a scripts $kerneldir/build

        if [ -d arch/${ARCH}/scripts ]; then
	    cp -a arch/${ARCH}/scripts $kerneldir/build/arch/${ARCH}
	fi
	if [ -f arch/${ARCH}/*lds ]; then
	    cp -a arch/${ARCH}/*lds $kerneldir/build/arch/${ARCH}
	fi

	rm -f $kerneldir/build/scripts/*.o
	rm -f $kerneldir/build/scripts/*/*.o

	if [ "${ARCH}" = "powerpc" ]; then
	    if [ -e arch/powerpc/lib/crtsavres.S ] ||
		   [ -e arch/powerpc/lib/crtsavres.o ]; then
		cp -a --parents arch/powerpc/lib/crtsavres.[So] $kerneldir/build/
	    fi
	fi

	if [ "${ARCH}" = "arm64" ]; then
	    cp -a --parents arch/arm64/kernel/vdso/vdso.lds $kerneldir/build/
	fi

	cp -a include $kerneldir/build/include
    )

    # now grab the chunks from the source tree that we need
    (
	cd $S

	cp -a scripts $kerneldir/build

	# if our build dir had objtool, it will also be rebuilt on target, so
	# we copy what is required for that build
	if [ -f $B/tools/objtool/objtool ]; then
	    # these are a few files associated with objtool, since we'll need to
	    # rebuild it
	    cp -a --parents tools/build/Build.include $kerneldir/build/
	    cp -a --parents tools/build/Build $kerneldir/build/
	    cp -a --parents tools/build/fixdep.c $kerneldir/build/
	    cp -a --parents tools/scripts/utilities.mak $kerneldir/build/

	    # extra files, just in case
	    cp -a --parents tools/objtool/* $kerneldir/build/
	    cp -a --parents tools/lib/* $kerneldir/build/
	    cp -a --parents tools/lib/subcmd/* $kerneldir/build/

	    cp -a --parents tools/include/* $kerneldir/build/

	    cp -a --parents $(find tools/arch/${ARCH}/ -type f) $kerneldir/build/
	fi

	if [ "${ARCH}" = "arm64" ]; then
	    # arch/arm64/include/asm/xen references arch/arm
	    cp -a --parents arch/arm/include/asm/xen $kerneldir/build/
	    # arch/arm64/include/asm/opcodes.h references arch/arm
	    cp -a --parents arch/arm/include/asm/opcodes.h $kerneldir/build/

            cp -a --parents arch/arm64/kernel/vdso/*gettimeofday.* $kerneldir/build/
            cp -a --parents arch/arm64/kernel/vdso/sigreturn.S $kerneldir/build/
            cp -a --parents arch/arm64/kernel/vdso/note.S $kerneldir/build/
            cp -a --parents arch/arm64/kernel/vdso/gen_vdso_offsets.sh $kerneldir/build/

            cp -a --parents arch/arm64/kernel/module.lds $kerneldir/build/ 2>/dev/null || :
	fi

	if [ "${ARCH}" = "powerpc" ]; then
	    # 5.0 needs these files, but don't error if they aren't present in the source
	    cp -a --parents arch/${ARCH}/kernel/syscalls/syscall.tbl $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/${ARCH}/kernel/syscalls/syscalltbl.sh $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/${ARCH}/kernel/syscalls/syscallhdr.sh $kerneldir/build/ 2>/dev/null || :
	fi

	# include the machine specific headers for ARM variants, if available.
	if [ "${ARCH}" = "arm" ]; then
	    cp -a --parents arch/${ARCH}/mach-*/include $kerneldir/build/

	    # include a few files for 'make prepare'
	    cp -a --parents arch/arm/tools/gen-mach-types $kerneldir/build/
	    cp -a --parents arch/arm/tools/mach-types $kerneldir/build/

	    # ARM syscall table tools only exist for kernels v4.10 or later
            SYSCALL_TOOLS=$(find arch/arm/tools -name "syscall*")
            if [ -n "$SYSCALL_TOOLS" ] ; then
	        cp -a --parents $SYSCALL_TOOLS $kerneldir/build/
            fi

            cp -a --parents arch/arm/kernel/module.lds $kerneldir/build/
	fi

	if [ -d arch/${ARCH}/include ]; then
	    cp -a --parents arch/${ARCH}/include $kerneldir/build/
	fi

	cp -a include $kerneldir/build

	cp -a --parents lib/vdso/* $kerneldir/build/ 2>/dev/null || :

	cp -a --parents tools/include/tools/le_byteshift.h $kerneldir/build/
	cp -a --parents tools/include/tools/be_byteshift.h $kerneldir/build/

	# required for generate missing syscalls prepare phase
	cp -a --parents $(find arch/x86 -type f -name "syscall_32.tbl") $kerneldir/build
	cp -a --parents $(find arch/arm -type f -name "*.tbl") $kerneldir/build 2>/dev/null || :

	if [ "${ARCH}" = "x86" ]; then
	    # files for 'make prepare' to succeed with kernel-devel
	    cp -a --parents $(find arch/x86 -type f -name "syscall_32.tbl") $kerneldir/build/
	    cp -a --parents $(find arch/x86 -type f -name "syscalltbl.sh") $kerneldir/build/
	    cp -a --parents $(find arch/x86 -type f -name "syscallhdr.sh") $kerneldir/build/
	    cp -a --parents $(find arch/x86 -type f -name "syscall_64.tbl") $kerneldir/build/
	    cp -a --parents arch/x86/tools/relocs_32.c $kerneldir/build/
	    cp -a --parents arch/x86/tools/relocs_64.c $kerneldir/build/
	    cp -a --parents arch/x86/tools/relocs.c $kerneldir/build/
	    cp -a --parents arch/x86/tools/relocs_common.c $kerneldir/build/
	    cp -a --parents arch/x86/tools/relocs.h $kerneldir/build/
	    cp -a --parents arch/x86/tools/gen-insn-attr-x86.awk $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/x86/purgatory/purgatory.c $kerneldir/build/

	    # 4.18 + have unified the purgatory files, so we ignore any errors if
	    # these files are not present
	    cp -a --parents arch/x86/purgatory/sha256.h $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/x86/purgatory/sha256.c $kerneldir/build/ 2>/dev/null || :

	    cp -a --parents arch/x86/purgatory/stack.S $kerneldir/build/
	    cp -a --parents arch/x86/purgatory/string.c $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/x86/purgatory/setup-x86_64.S $kerneldir/build/
	    cp -a --parents arch/x86/purgatory/entry64.S $kerneldir/build/
	    cp -a --parents arch/x86/boot/string.h $kerneldir/build/
	    cp -a --parents arch/x86/boot/string.c $kerneldir/build/
	    cp -a --parents arch/x86/boot/compressed/string.c $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/x86/boot/ctype.h $kerneldir/build/

	    # objtool requires these files
	    cp -a --parents arch/x86/lib/inat.c $kerneldir/build/ 2>/dev/null || :
	    cp -a --parents arch/x86/lib/insn.c $kerneldir/build/ 2>/dev/null || :
	fi

	if [ "${ARCH}" = "mips" ]; then
	    cp -a --parents arch/mips/Kbuild.platforms $kerneldir/build/
	    cp --parents $(find	 -type f -name "Platform") $kerneldir/build
	    cp --parents arch/mips/boot/tools/relocs* $kerneldir/build
	    cp -a --parents arch/mips/kernel/asm-offsets.c $kerneldir/build
	    cp -a --parents kernel/time/timeconst.bc $kerneldir/build
	    cp -a --parents kernel/bounds.c $kerneldir/build
	    cp -a --parents Kbuild $kerneldir/build
	    cp -a --parents arch/mips/kernel/syscalls/*.sh $kerneldir/build 2>/dev/null || :
	    cp -a --parents arch/mips/kernel/syscalls/*.tbl $kerneldir/build 2>/dev/null || :
	    cp -a --parents arch/mips/tools/elf-entry.c $kerneldir/build 2>/dev/null || :
	fi

        # required to build scripts/selinux/genheaders/genheaders
        cp -a --parents security/selinux/include/* $kerneldir/build/

	# copy any localversion files
	cp -a localversion* $kerneldir/build/ 2>/dev/null || :
    )

    # Make sure the Makefile and version.h have a matching timestamp so that
    # external modules can be built
    touch -r $kerneldir/build/Makefile $kerneldir/build/include/generated/uapi/linux/version.h

    # Copy .config to include/config/auto.conf so "make prepare" is unnecessary.
    cp $kerneldir/build/.config $kerneldir/build/include/config/auto.conf

    # make the scripts python3 safe. We won't be running these, and if they are
    # left as /usr/bin/python rootfs assembly will fail, since we only have python3
    # in the RDEPENDS (and the python3 package does not include /usr/bin/python)
    for ss in $(find $kerneldir/build/scripts -type f -name '*'); do
	sed -i 's,/usr/bin/python2,/usr/bin/env python3,' "$ss"
	sed -i 's,/usr/bin/env python2,/usr/bin/env python3,' "$ss"
	sed -i 's,/usr/bin/python,/usr/bin/env python3,' "$ss"
    done

    # specific files required for AXXIA kernel sources
    (
        cd $S

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
        cd $B
        cp --parents $(find  -type f -name "unistd_*.h") $kerneldir/build
    )

    # enforce all scripts to use /usr/bin/awk
    (
        cd ${D}
        for i in $(grep -srI "\!/bin/awk" | cut -d":" -f1); do
            sed -i -e "s#\!/bin/awk#\!/usr/bin/env awk#g" $i
        done
    )

    chown -R root:root ${D}
}

fakeroot do_install_alternative_kernels() {
    for kernel in ${ALTERNATIVE_KERNELS}; do
        S="${TMPDIR}/work-shared/${MACHINE}/kernel-source-$kernel"
        B="${TMPDIR}/work-shared/${MACHINE}/kernel-build-artifacts-$kernel"
        KERNEL_VERSION="$(cat $B/kernel-$kernel-abiversion)"
        do_install
    done
}
addtask do_install_alternative_kernels after do_install before do_package
do_install_alternative_kernels[depends] += "virtual/fakeroot-native:do_populate_sysroot"
