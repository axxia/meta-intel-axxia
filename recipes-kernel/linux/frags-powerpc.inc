# depending on SMP settings, debug fragments are different for 4.1 standard Kernel:
# SMP == no && KV == 4.1 && LINUX_KERNEL_TYPE == standard -> use dbg-nosmp fragment
DBG_VERSION = "${@base_conditional('SMP', 'no', base_conditional('KV', '4.1', \
                  base_conditional('LINUX_KERNEL_TYPE', 'standard', 'dbg-nosmp', 'dbg', d), 'dbg', d), 'dbg', d)}"

# adding fragments with kernel options to the final .config
SRC_URI += "file://common.scc \
	${@base_conditional('SMP', 'yes', 'file://smp.scc', '', d)} \
	${@base_conditional('LINUX_KERNEL_TYPE', 'preempt-rt', 'file://preempt-rt.scc', 'file://standard.scc', d)} \
	${@base_conditional('DBG', 'yes', 'file://${DBG_VERSION}.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', 'file://non-testing.scc', d)} "
