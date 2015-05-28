
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

COMPATIBLE_MACHINE = "axxiaarm|axxiapowerpc"

KMACHINE = "${MACHINE}"

INSANE_SKIP_kernel-dev = "debug-files"

PARALLEL_MAKE = ""

mk_fit_images() {
	name=$1
	addr=$2
	oe_runmake ${name}.dtb
	echo "pwd = `pwd`"
	cd ../fit
	if [ "${KARCH}" = "arm" ] && [ "${KV}" = "3.10" ]
	then
		oe_runmake "ARCH=${KARCH}" \
				'DESCRIPTION=LSI Axxia Linux' \
				"ADDRESS=${addr}" \
				'VMLINUX=${B}/vmlinux' \
				"DTB=${B}/arch/${KARCH}/boot/dts/${name}.dtb"
	else
		oe_runmake "ARCH=${KARCH}" \
       	                        'DESCRIPTION=LSI Axxia Linux' \
               	                "ADDRESS=${addr}" \
                       	        'VMLINUX=${B}/vmlinux' \
                               	"DTB=${B}/arch/${KARCH}/boot/${name}.dtb"
	fi
	mv linux.fit linux.fit-${name}
	mv fdt.fit fdt.fit-${name}
	mv multi.fit multi.fit-${name}
	cd ${B}
}

do_compile_append() {
    if [ "${KARCH}" = "powerpc" ]
    then
    	addr=0x00400000
		mk_fit_images "acp25xx" ${addr}
		mk_fit_images "acp342x" ${addr}
		mk_fit_images "acp344x" ${addr}
		mk_fit_images "acp35xx" ${addr}
	fi
	if [ "${KARCH}" = "arm" ]
	then
		addr=0x00408000
		if [ "${KV}" = "3.10" ]
		then
			mk_fit_images "axm5504-emu" ${addr}
			mk_fit_images "axm5507-emu" ${addr}
			mk_fit_images "axm5516-amarillo" ${addr}
#			if [ "${LSI_SRC}" = "linux-yocto" ]
#			then
#				mk_fit_images "axm5504-sim" ${addr}
#				mk_fit_images "axm5516-sim" ${addr}
#			else
				mk_fit_images "axm5504-sim-mmc" ${addr}
                        	mk_fit_images "axm5504-sim-virtio" ${addr}
				mk_fit_images "axm5516-sim-mmc" ${addr}
                        	mk_fit_images "axm5516-sim-virtio" ${addr}
#			fi
		fi
	fi
}

install_fit_images() {
	name=$1
	if [ "${KARCH}" = "arm" ] && [ "${KV}" = "3.10" ]
	then
		install ${B}/arch/${KARCH}/boot/dts/${name}.dtb ${DEPLOYDIR}/${name}.dtb
	else
		install ${B}/arch/${KARCH}/boot/${name}.dtb ${DEPLOYDIR}/${name}.dtb
	fi
	install ${B}/../fit/linux.fit-${name} ${DEPLOYDIR}/linux.fit-${name}
	install ${B}/../fit/fdt.fit-${name} ${DEPLOYDIR}/fdt.fit-${name}
	install ${B}/../fit/multi.fit-${name} ${DEPLOYDIR}/multi.fit-${name}
	
}

do_deploy_append() {
    if [ "${KARCH}" = "powerpc" ]
    then
    	install_fit_images "acp25xx"
		install_fit_images "acp342x"
		install_fit_images "acp344x"
		install_fit_images "acp35xx"
	fi
    if [ "${KARCH}" = "arm" ]
    then
		if [ "${KV}" = "3.10" ]
		then
	    		install_fit_images "axm5504-emu"
			install_fit_images "axm5507-emu"
			install_fit_images "axm5516-amarillo"
#			if [ "${LSI_SRC}" = "linux-yocto" ]
#			then
#				install_fit_images "axm5504-sim"
#				install_fit_images "axm5516-sim"	
#			else
				install_fit_images "axm5504-sim-mmc"
				install_fit_images "axm5504-sim-virtio"
				install_fit_images "axm5516-sim-mmc"
                		install_fit_images "axm5516-sim-virtio"
#			fi
    	fi
    fi
}

do_patch_append() {
	if [ "${LSI_SRC}" != "linux-yocto" ]
	then
		if [ "${PN}" = "linux-yocto" ]
		then
			cp ${WORKDIR}/linux/arch/${KARCH}/configs/lsi_defconfig ${WORKDIR}/defconfig
		elif [ "${PN}" = "linux-yocto-rt" ]
		then
			cp ${WORKDIR}/linux/arch/${KARCH}/configs/lsi_rt_defconfig ${WORKDIR}/defconfig
		fi
	fi
}
