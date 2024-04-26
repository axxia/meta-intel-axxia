FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

LTTNG_PERF_FIX_FOR_6.6.0 ??= "0"

SRC_URI:append = " ${@oe.utils.conditional('LTTNG_PERF_FIX_FOR_6.6.0', '1', \
	'file://0001-perf-Fix-arguments-for-perf_event_create_group_kerne.patch', '', d)}"

# If clean or cleansstate is run for lttng-modules, clean also alternative lttng-modules
LTTNG_MODULES_CLEAN = "${@':do_clean '.join(d.getVar('ALTERNATIVE_KERNELS_LTTNG_MODULES')[1:].split(' '))}:do_clean"
LTTNG_MODULES_CLEANSSTATE = "${@':do_cleansstate '.join(d.getVar('ALTERNATIVE_KERNELS_LTTNG_MODULES')[1:].split(' '))}:do_cleansstate"

do_clean[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${LTTNG_MODULES_CLEAN}', d)}"
do_cleansstate[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${LTTNG_MODULES_CLEANSSTATE}', d)}"
