FILESEXTRAPATHS_prepend := "${THISDIR}/conf/linux-yocto/linux-3.10/${MACHINE}:\
${THISDIR}/conf/linux-yocto/linux-3.10/${MACHINE}/dbg-ppc:"

# adding fragments with kernel options to the final .config
KERNEL_EXTRA_FEATURES = ""
SRC_URI += "file://axxiapowerpc-common.scc \
	${@base_conditional('LINUX_KERNEL_TYPE', 'preempt-rt', 'file://axxiapowerpc-preempt-rt.scc', '', d)} \
	${@base_conditional('DBG', 'yes', 'file://dbg.scc', '', d)} \
	${@base_conditional('TESTING', 'yes', 'file://testing.scc', 'file://non-testing.scc', d)} "
