# adding fragments with kernel options to the final .config
SRC_URI += "file://common.scc file://lxc.scc \
	${@base_conditional('SMP', 'yes', 'file://smp.scc', '', d)} \
	${@base_conditional('LINUX_KERNEL_TYPE', 'preempt-rt', 'file://preempt-rt.scc', '', d)} \
	${@base_conditional('DBG', 'yes', 'file://dbg.scc file://dbg-extra.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', '', d)} "

# adding fragment to distinguish between X9 and XLF on 4.9 and 4.1 kernels
SRC_URI += "${@base_conditional('CHIPSET', 'XLF', 'file://xlf.scc', '', d)}"
