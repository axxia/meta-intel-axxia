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
