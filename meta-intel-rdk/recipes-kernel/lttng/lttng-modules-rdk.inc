USE_RDK_REPO ?= "false"
RDK_REPO ?= ""
RDK_REPO_REV ?= ""
RDK_REPO_SRC_URI ?= "git://${@d.getVar('RDK_REPO').replace('https://','')};protocol=https;nobranch=1;name=rdk;subpath=rdk/klm;destsuffix=rdk/klm"
SRCREV_rdk = "${RDK_REPO_REV}"

FILESEXTRAPATHS:prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"
RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"

SRC_URI:append = " ${@oe.utils.conditional('USE_RDK_REPO', 'false', '${RDK_KLM_ARCHIVE}', '${RDK_REPO_SRC_URI}', d)}"

export RDK_KLM_VERSION

do_patch_rdk() {
    cd ${S}
    VERSION="${PV}"
    [ -z $(find ${WORKDIR}/rdk/klm -path "*lttng/${VERSION%.*}") ] \
        && PATTERN="*/lttng/*.patch" || PATTERN="*/lttng/${VERSION%.*}/*.patch"
    RDK_LTTNG_PATCHES=$(find ${WORKDIR}/rdk/klm -path "${PATTERN}")
    if [ ! -z "${RDK_LTTNG_PATCHES}" ]; then
        cp ${RDK_LTTNG_PATCHES} ${S}
        ls ${S}/*.patch | sort | xargs -t -n 1 patch -p1 -i
    fi
}
do_patch[postfuncs] += "do_patch_rdk"

do_compile:prepend() {
    # If no version for KLM modules is set in local.conf, get the value from
    # rdk-klm-version file exported by the kernel recipe (linux-rdk.inc) in a
    # shared location (STAGING_KERNEL_BUILDDIR) for external modules recipes.
    # For alternative kernels, the shared location is customized (KERNEL_OUTPUT)
    [ "${PN}" = "lttng-modules" ] && kpath=${STAGING_KERNEL_BUILDDIR} \
                                   || kpath=${KERNEL_OUTPUT}
    [ -z "${RDK_KLM_VERSION}" -a -f $kpath/rdk-klm-version ] && \
        export RDK_KLM_VERSION="$(cat $kpath/rdk-klm-version)"
}
