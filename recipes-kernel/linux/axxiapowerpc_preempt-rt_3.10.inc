# adding fragments with kernel options to the final .config
KERNEL_EXTRA_FEATURES = ""
SRC_URI += "file://common.scc \
	file://preempt-rt.scc \
	${@base_conditional('DBG', 'yes', 'file://dbg.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', 'file://non-testing.scc', d)} "
