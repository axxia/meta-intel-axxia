# Ensure kernel artifacts are deployed in work-shared
do_compile[depends] += "${PREFERRED_PROVIDER_virtual/kernel}:do_deploy"

# If clean or cleansstate is run for lttng-modules, clean also alternative lttng-modules
LTTNG_MODULES_CLEAN = "${@':do_clean '.join(d.getVar('ALTERNATIVE_KERNELS_LTTNG_MODULES')[1:].split(' '))}:do_clean"
LTTNG_MODULES_CLEANSSTATE = "${@':do_cleansstate '.join(d.getVar('ALTERNATIVE_KERNELS_LTTNG_MODULES')[1:].split(' '))}:do_cleansstate"

do_clean[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${LTTNG_MODULES_CLEAN}', d)}"
do_cleansstate[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${LTTNG_MODULES_CLEANSSTATE}', d)}"
