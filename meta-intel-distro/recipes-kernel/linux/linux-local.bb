########################## linux-local.bb ############################
# Simple recipe to build kernel from local repository.               #
# Set linux-local as PREFERRED_PROVIDER for virtual/kernel component #
#     PREFERRED_PROVIDER_virtual/kernel = "linux-local"              #
# To build only the kernel run:                                      #
#      $ bitbake linux-local                                         #
# All changes should be committed in the local kernel clone.         #
# Full defconfig should be copied in this directory (besides recipe) #
# If you want to skip lttng support for your kernel:                 #
#      LTTNG_SUPPORT = ""                                            #
######################################################################

# Adjust the following lines with the kernel path and branch
LOCAL_KERNEL_PATH ?= "path-to-local-kernel-repository"
LOCAL_KERNEL_BRANCH ?= "standard/base"

require recipes-kernel/linux/linux-yocto.inc \
	${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-rdk', \
			     'recipes-kernel/linux/linux-rdk.inc', '', d)}

LINUX_VERSION_EXTENSION = "-intel-axxia-local-dev"

FILESEXTRAPATHS_prepend := "${THISDIR}:"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

PV = "dev-version"

DEPENDS_append = " elfutils-native openssl-native util-linux-native"

SRCREV_machine = "${AUTOREV}"

SRC_URI = " \
	git://${LOCAL_KERNEL_PATH};name=machine;branch=${LOCAL_KERNEL_BRANCH} \
	file://defconfig \
	"

do_kernel_configme[depends] += "${PN}:do_prepare_recipe_sysroot"

COMPATIBLE_MACHINE_intel-axxia-snr = "${MACHINE}"
COMPATIBLE_MACHINE_intel-axxia-grr = "${MACHINE}"
KERNEL_VERSION_SANITY_SKIP = "1"
