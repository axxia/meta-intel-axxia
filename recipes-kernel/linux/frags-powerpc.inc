# depending on SMP settings, debug fragments are different for 3.14 standard Kernel:
# SMP == no && KV == 3.14 && LINUX_KERNEL_TYPE == standard -> use dbg-nosmp fragment
DBG_TEST_SMP = "${@base_conditional('SMP', 'yes', 'dbg', 'dbg-nosmp', d)}"
DBG_TEST_KERNEL = "${@base_conditional('KV', '3.14', '${DBG_TEST_SMP}', 'dbg', d)}"
DBG_VERSION = "${@base_conditional('LINUX_KERNEL_TYPE', 'standard', '${DBG_TEST_KERNEL}', 'dbg', d)}"

# adding fragments with kernel options to the final .config
SRC_URI += "file://common.scc \
	${@base_conditional('SMP', 'yes', 'file://smp.scc', '', d)} \
	${@base_conditional('LINUX_KERNEL_TYPE', 'preempt-rt', 'file://preempt-rt.scc', 'file://standard.scc', d)} \
	${@base_conditional('DBG', 'yes', 'file://${DBG_VERSION}.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', 'file://non-testing.scc', d)} "
