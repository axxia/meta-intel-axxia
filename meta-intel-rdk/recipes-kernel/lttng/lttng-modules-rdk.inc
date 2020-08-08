FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

export RDK_KLM_VERSION

SRC_URI_append = " \
	file://0001-Add-tracepoints-module-for-CPK-AE-driver.patch \
	file://0002-Add-tracepoints-module-for-ADK-NetD-driver.patch \
"

do_compile_prepend() {
    # If no version for KLM modules is set in local.conf, get the value from
    # rdk-klm-version file exported by the kernel recipe (linux-rdk.inc) in a
    # shared location (STAGING_KERNEL_BUILDDIR) for external modules recipes.
    # For alternative kernels, the shared location is customized (KERNEL_OUTPUT)
    [ "${PN}" == "lttng-modules" ] && kpath=${STAGING_KERNEL_BUILDDIR} \
                                   || kpath=${KERNEL_OUTPUT}
    [ -z "${RDK_KLM_VERSION}" -a -f $kpath/rdk-klm-version ] && \
        export RDK_KLM_VERSION="$(cat $kpath/rdk-klm-version)"
}
