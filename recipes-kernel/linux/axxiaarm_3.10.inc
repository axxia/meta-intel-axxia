FILESEXTRAPATHS_prepend := "${THISDIR}/conf/linux-yocto/linux-3.10/${MACHINE}:\
${THISDIR}/conf/linux-yocto/linux-3.10/${MACHINE}/big-endian:\
${THISDIR}/conf/linux-yocto/linux-3.10/${MACHINE}/dbg-arm:"

# adding fragments with kernel options to the final .config
KERNEL_EXTRA_FEATURES = "features/taskstats/taskstats.scc"
SRC_URI += "file://axxiaarm-common.scc \
	${@base_conditional('LINUX_KERNEL_TYPE', 'preempt-rt', 'file://axxiaarm-preempt-rt.scc', '', d)} \
	${@base_conditional('BIG_ENDIAN', 'yes', 'file://big-endian.scc', '', d)} \
	${@base_conditional('DBG', 'yes', 'file://dbg.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', '', d)} "

# cpu hotplug  options: low power (default), full power down, full power down with L2 cache
SRC_URI += "${@base_conditional('POWER_MANAGEMENT', 'full-power', 'file://power-management-full-power.scc', '', d)} \
	${@base_conditional('POWER_MANAGEMENT', 'full-power-L2', 'file://power-management-full-power-L2.scc', '', d)} \
	${@base_conditional('POWER_MANAGEMENT', 'low-power', 'file://power-management-low-power.scc', '', d)} "
