IES_ENABLE_SHM ?= "true"

BBFILES += "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '${BBFILES_COMMON_DIR}', '', d)}"
BBFILES_COMMON_DIR = "${LAYERDIR}/../common/recipes-*/*/*.bb \
		      ${LAYERDIR}/../common/recipes-*/*/*.bbappend"

# Set specific versions required by RDK drivers/tools on RPC (remote procedure call) mode
PREFERRED_VERSION_thrift        ??= "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '0.11.0', '', d)}"
PREFERRED_VERSION_thrift-native ??= "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '0.11.0', '', d)}"
PREFERRED_VERSION_boost         ??= "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '1.70.0', '', d)}"
PREFERRED_VERSION_boost-native  ??= "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '1.70.0', '', d)}"
PREFERRED_VERSION_bjam-native   ??= "${@bb.utils.contains('IES_ENABLE_SHM', 'false', '1.70.0', '', d)}"

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
