IES_ENABLE_SHM ?= "true"

BBFILES += "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '${BBFILES_COMMON_DIR}', '', d)}"
BBFILES_COMMON_DIR = "${LAYERDIR}/../common/recipes-*/*/*.bb \
		      ${LAYERDIR}/../common/recipes-*/*/*.bbappend"

# Skip lttng-modules recipes for alternative kernels if meta-intel-distro layer is not used
# or alternative kernels are not supported
# Skip parsing rdk-tools recipe if rdk-userspace feature is not enabled
BBMASK += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', \
		'meta-intel-rdk/recipes-kernel/lttng/lttng-modules-alternative*', '', d)} \
	   ${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-distro', \
		'', 'meta-intel-rdk/recipes-kernel/lttng/lttng-modules-alternative*', d)} \
	   ${@bb.utils.contains('DISTRO_FEATURES', 'rdk-userspace', \
		'', 'recipes-extended/rdk-tools', d)} \
	  "
