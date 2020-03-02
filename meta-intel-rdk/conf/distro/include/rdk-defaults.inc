# Set specific versions required by RDK drivers/tools
PREFERRED_VERSION_thrift ?= "0.11.0"
PREFERRED_VERSION_thrift-native ?= "0.11.0"

# Location to populate with the RDK source code archive
RDK_ARCHIVE_PATH ?= "${LAYERDIR}/downloads"

# Variables for each RDK source code archive
RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"
RDK_TOOLS_ARCHIVE ?= "file://rdk_user_src.tar.xz"

IMAGE_INSTALL_append_axxiax86-64 = " linux-firmware-klm-qat \
${PREFERRED_PROVIDER_virtual/kernel}-kernel-headers \
${@bb.utils.contains('DISTRO_FEATURES', 'rdk-userspace', \
                     'rdk-tools rdk-tools-dev', '', d)}"

# Enable RDK userspace support
#DISTRO_FEATURES_append = " rdk-userspace"
