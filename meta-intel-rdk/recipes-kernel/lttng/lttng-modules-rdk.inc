FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"

RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"

SRC_URI_append = " ${RDK_KLM_ARCHIVE}"

export RDK_KLM_VERSION

do_patch_rdk() {
	cd ${S}
	cp $(find ${WORKDIR}/rdk/klm -path "*/lttng/*.patch") ${S}
	ls ${S}/*.patch | sort | xargs -t -n 1 patch -p1 -i
}
do_patch[postfuncs] += "do_patch_rdk"

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
