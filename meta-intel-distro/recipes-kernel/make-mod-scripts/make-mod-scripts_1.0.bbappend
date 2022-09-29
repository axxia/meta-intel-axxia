ALTERNATIVE_KERNELS_SHARED_WORKDIR  = "${@':do_shared_workdir '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}"
ALTERNATIVE_KERNELS_COMPILE_MODULES = "${@':do_compile_kernelmodules '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}"

do_configure[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', \
                         '${ALTERNATIVE_KERNELS_SHARED_WORKDIR}:do_shared_workdir', d)}"
do_compile[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', \
                       '${ALTERNATIVE_KERNELS_COMPILE_MODULES}:do_compile_kernelmodules', d)}"

# Build some host tools under work-shared for alternative kernels
do_configure:append() {
    for kernel in ${ALTERNATIVE_KERNELS}; do
        oe_runmake CC="${KERNEL_CC}" LD="${KERNEL_LD}" AR="${KERNEL_AR}" \
            -C ${TMPDIR}/work-shared/${MACHINE}/kernel-source-$kernel \
            O=${TMPDIR}/work-shared/${MACHINE}/kernel-build-artifacts-$kernel \
            scripts prepare
    done
}
