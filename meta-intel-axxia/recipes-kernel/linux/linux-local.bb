########################## linux-local.bb ############################
# Simple recipe to build kernel from local repository.               #
# Set linux-local as PREFERRED_PROVIDER for virtual/kernel component #
#     PREFERRED_PROVIDER_virtual/kernel = "linux-local"              #
# To build only the kernel run:                                      #
#      $ bitbake linux-local                                         #
# All changes should be committed in the local kernel clone.         #
# Full defconfig should be copied in this directory (besides recipe) #
# Adjust the following lines with the kernel path and branch.        #
######################################################################

LOCAL_KERNEL_PATH ?= "path-to-local-kernel-repository"
LOCAL_KERNEL_BRANCH ?= "standard/base"

require recipes-kernel/linux/linux-yocto.inc

LINUX_VERSION_EXTENSION = "-intel-axxia-local-dev"

FILESEXTRAPATHS_prepend := "${THISDIR}:"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

PV = "dev-version"

DEPENDS_append = " elfutils-native openssl-native util-linux-native"

SRCREV_machine_axxiax86-64 = "${AUTOREV}"

SRC_URI_axxiax86-64 = " \
	git://${LOCAL_KERNEL_PATH};name=machine;branch=${LOCAL_KERNEL_BRANCH} \
	file://defconfig \
	"

do_kernel_configme[depends] += "${PN}:do_prepare_recipe_sysroot"

COMPATIBLE_MACHINE_axxiax86-64 = "${MACHINE}"
KERNEL_VERSION_SANITY_SKIP = "1"
