# adding fragments with kernel options to the final .config
KERNEL_EXTRA_FEATURES = "features/taskstats/taskstats.scc"
SRC_URI += "file://common.scc \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', '', d)} "

# cpu hotplug  options: low power (default), full power down, full power down with L2 cache
SRC_URI += "${@base_conditional('POWER_MANAGEMENT', 'full-power', 'file://full-power.scc', '', d)} \
	${@base_conditional('POWER_MANAGEMENT', 'full-power-L2', 'file://full-power-L2.scc', '', d)} \
	${@base_conditional('POWER_MANAGEMENT', 'low-power', 'file://low-power.scc', '', d)} "
