FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"

RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"

SRC_URI_append = " ${RDK_KLM_ARCHIVE}"

export RDK_KLM_VERSION

do_patch_rdk() {
	cd ${S}
	for fname in $(find ${WORKDIR}/rdk/klm/*/lttng -type f -name "*.patch" -printf '%f\n' | sort); do
		find ${WORKDIR}/rdk/klm/*/lttng -type f -name $fname | xargs -t -n 1 patch -p1 -i
	done
}
do_patch[postfuncs] += "do_patch_rdk"
