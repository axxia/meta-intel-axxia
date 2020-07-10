FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

SRC_URI_append = " \
	file://0001-Add-tracepoints-module-for-CPK-AE-driver.patch \
"
