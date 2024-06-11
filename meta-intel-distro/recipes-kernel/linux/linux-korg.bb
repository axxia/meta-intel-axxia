############################## linux-korg.bb ##############################
# Simple recipe to build linux from KERNEL.ORG                            #
# Set linux-korg as PREFERRED_PROVIDER for virtual/kernel in local.conf:  #
#     PREFERRED_PROVIDER_virtual/kernel = "linux-korg"                    #
#                                                                         #
# To build a specific release tag from the official kernel.org refs page: #
# https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/refs #
# set the tag in KORG_VERSION variable (latest will be used by default):  #
#      KORG_VERSION = "v6.9-rc5"                                          #
#                                                                         #
# Full defconfig should be copied besides this recipe or in a 'files'     #
# directory created in the recipe location.                               #
#                                                                         #
# To add local patches to the kernel, copy them besides defconfig and add #
# them in SRC_URI:                                                        #
#      SRC_URI += " files://Name-of-the.patch"                            #
#                                                                         #
# If you want to skip lttng support for your kernel:                      #
#      LTTNG_SUPPORT = ""                                                 #
###########################################################################

inherit kernel
require recipes-kernel/linux/linux-yocto.inc \
	${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-rdk', \
			     'recipes-kernel/linux/linux-rdk.inc', '', d)}

FILESEXTRAPATHS:prepend := "${THISDIR}:"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

KORG_VERSION ?= "latest"

PV = "${KORG_VERSION}"

LINUX_VERSION_EXTENSION = "-kernel-org-${KORG_VERSION}"

DEPENDS:append = " elfutils-native openssl-native util-linux-native"

SRC_URI = " git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=http;branch=master;name=machine \
	file://defconfig \
	"

do_kernel_configme[depends] += "${PN}:do_prepare_recipe_sysroot"

COMPATIBLE_MACHINE:intel-axxia-snr = "${MACHINE}"
COMPATIBLE_MACHINE:intel-axxia-grr = "${MACHINE}"
COMPATIBLE_MACHINE:intel-axxia-pmr = "${MACHINE}"

KERNEL_VERSION_SANITY_SKIP = "1"
KERNEL_DANGLING_FEATURES_WARN_ONLY = "0"

python __anonymous() {
    rev = d.getVar('KORG_VERSION')
    if rev == "latest":
       d.setVar("SRCREV_machine", "${AUTOREV}")
    else:
       d.setVar("SRCREV_machine", rev)
}
