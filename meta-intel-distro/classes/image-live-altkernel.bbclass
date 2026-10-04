inherit image-live

do_bootimg[depends] += "${ALTERNATIVE_KERNELS_DEPLOY}"

LABELS_LIVE = "boot ${ALTERNATIVE_KERNELS_BOOT_LABELS} install"

populate_altkernel() {
	install -d ${HDDDIR} ${ISODIR} ${EFIIMGDIR}

	if [ -n "${ALTERNATIVE_KERNELS}" ]; then
		bbnote "Trying to install alternative kernels: ${ALTERNATIVE_KERNELS}"
		for k in ${ALTERNATIVE_KERNELS}; do
			bbnote "Trying to install ${DEPLOY_DIR_IMAGE}/altkernel-$k/${KERNEL_IMAGETYPE} as ${KERNEL_IMAGETYPE}-$k"
			if [ -e ${DEPLOY_DIR_IMAGE}/altkernel-$k/${KERNEL_IMAGETYPE} ]; then
				install -m 0644 ${DEPLOY_DIR_IMAGE}/altkernel-$k/${KERNEL_IMAGETYPE} ${HDDDIR}/${KERNEL_IMAGETYPE}-$k
				install -m 0644 ${DEPLOY_DIR_IMAGE}/altkernel-$k/${KERNEL_IMAGETYPE} ${ISODIR}/${KERNEL_IMAGETYPE}-$k
				install -m 0644 ${DEPLOY_DIR_IMAGE}/altkernel-$k/${KERNEL_IMAGETYPE} ${EFIIMGDIR}/${KERNEL_IMAGETYPE}-$k
			else
				bbwarn "${DEPLOY_DIR_IMAGE}/altkernel-$k/${KERNEL_IMAGETYPE} doesn't exist"
			fi
		done
	fi
}

customize_cfg() {
	if [ -n "${ALTERNATIVE_KERNELS}" ]; then
		for k in ${ALTERNATIVE_KERNELS}; do
			if [ -f "${GRUB_CFG_LIVE}" ];then
				sed -i "s/bzImage LABEL=boot-$k/bzImage-$k LABEL=boot-$k/g" ${GRUB_CFG_LIVE}
			fi
			if [ -f "${SYSLINUX_CFG_LIVE}" ]; then
				sed -i "/^LABEL .*boot-$k$/ {n; s|^KERNEL .*|KERNEL /bzImage-$k|}" ${SYSLINUX_CFG_LIVE}
			fi
		done
	fi
}

# Overwrite do_bootimg function from image-live.bbclass to add populate_altkernel
# and customize_cfg functions before building hddimg and iso images
python do_bootimg() {
    set_live_vm_vars(d, 'LIVE')
    if d.getVar("PCBIOS") == "1":
        bb.build.exec_func('build_syslinux_cfg', d)
    if d.getVar("EFI") == "1":
        bb.build.exec_func('build_efi_cfg', d)
        bb.build.exec_func('customize_cfg', d)
    bb.build.exec_func('populate_altkernel', d)
    bb.build.exec_func('build_hddimg', d)
    bb.build.exec_func('build_iso', d)
    bb.build.exec_func('create_symlinks', d)
}
