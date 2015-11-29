# adding fragments with kernel options to the final .config
SRC_URI += "file://common.scc \
	${@base_conditional('SMP', 'yes', 'file://smp.scc', '', d)} \
	${@base_conditional('LINUX_KERNEL_TYPE', 'preempt-rt', 'file://preempt-rt.scc', 'file://standard.scc', d)} \
	${@base_conditional('BIG_ENDIAN', 'yes', 'file://big-endian.scc', '', d)} \
	${@base_conditional('DBG', 'yes', 'file://dbg.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', '', d)} "

# cpu hotplug  options: low power (default), full power down, full power down with L2 cache
SRC_URI += "${@base_conditional('POWER_MANAGEMENT', 'full-power', 'file://full-power.scc', '', d)} \
	${@base_conditional('POWER_MANAGEMENT', 'full-power-L2', 'file://full-power-L2.scc', '', d)} \
	${@base_conditional('POWER_MANAGEMENT', 'low-power', 'file://low-power.scc', '', d)} "
