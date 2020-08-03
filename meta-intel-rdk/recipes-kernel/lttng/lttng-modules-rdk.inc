FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

export RDK_KLM_VERSION

SRC_URI_append = " \
	file://0001-Add-tracepoints-module-for-CPK-AE-driver.patch \
	file://0002-Add-tracepoints-module-for-ADK-NetD-driver.patch \
"
