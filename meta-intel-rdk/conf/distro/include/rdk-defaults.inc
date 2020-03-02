# Location to populate with the RDK source code archive
RDK_ARCHIVE_PATH ?= "${LAYERDIR}/downloads"

# Variables for each RDK source code archive
RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"
RDK_TOOLS_ARCHIVE ?= "file://rdk_user_src.tar.xz"

# Enable RDK userspace support
#DISTRO_FEATURES_append = " rdk-userspace"
