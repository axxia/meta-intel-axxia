FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append = " \
	file://0001-fix-KVM-x86-Use-gpa_t-for-cr2-gpa-to-fix-TDP-support.patch \
	file://0002-fix-ext4-limit-the-length-of-per-inode-prealloc-list.patch \
	file://0003-fix-writeback-Fix-sync-livelock-due-to-b_dirty_time-.patch \
	file://0004-fix-version-ranges-for-ext4_discard_preallocations-a.patch \
	"

# If clean or cleansstate is run for lttng-modules, clean also alternative lttng-modules
LTTNG_MODULES_CLEAN = "${@':do_clean '.join(d.getVar('ALTERNATIVE_KERNELS_LTTNG_MODULES')[1:].split(' '))}:do_clean"
LTTNG_MODULES_CLEANSSTATE = "${@':do_cleansstate '.join(d.getVar('ALTERNATIVE_KERNELS_LTTNG_MODULES')[1:].split(' '))}:do_cleansstate"

do_clean[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${LTTNG_MODULES_CLEAN}', d)}"
do_cleansstate[depends] += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${LTTNG_MODULES_CLEANSSTATE}', d)}"
