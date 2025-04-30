########################## linux-local.bb ############################
# Simple recipe to build kernel from local repository.               #
# Set linux-local as PREFERRED_PROVIDER for virtual/kernel component #
#     PREFERRED_PROVIDER_virtual/kernel = "linux-local"              #
#                                                                    #
# To build only the kernel run:                                      #
#      $ bitbake linux-local                                         #
#                                                                    #
# All changes should be committed in the local kernel clone.         #
#                                                                    #
# Full defconfig should be copied besides this recipe or in a 'files'#
# directory created in the recipe location.                          #
#                                                                    #
# If you want to skip lttng support for your kernel:                 #
#      LTTNG_SUPPORT = ""                                            #
######################################################################

# Adjust the following variables in local.conf
LOCAL_KERNEL_PATH ?= "path-to-local-kernel-repository"
LOCAL_KERNEL_BRANCH ?= "standard/base"
LOCAL_DEFCONFIG ?= ""
LOCAL_EXTRA_PATH ?= ""

inherit kernel
require recipes-kernel/linux/linux-yocto.inc \
	${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-rdk', \
			     'recipes-kernel/linux/linux-rdk.inc', '', d)}

LINUX_VERSION_EXTENSION = "-intel-axxia-local-dev"

FILESEXTRAPATHS:prepend := "${THISDIR}:\
${@oe.utils.conditional('LOCAL_EXTRA_PATH', '', '', '${LOCAL_EXTRA_PATH}:', d)}:"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

PV = "dev-version"

DEPENDS:append = " elfutils-native openssl-native util-linux-native"

SRCREV_machine = "${AUTOREV}"

SRC_URI = " git://${LOCAL_KERNEL_PATH};name=machine;branch=${LOCAL_KERNEL_BRANCH} \
	file://defconfig \
	"

do_kernel_configme[depends] += "${PN}:do_prepare_recipe_sysroot"

COMPATIBLE_MACHINE:intel-axxia-snr = "${MACHINE}"
COMPATIBLE_MACHINE:intel-axxia-grr = "${MACHINE}"
COMPATIBLE_MACHINE:intel-axxia-pmr = "${MACHINE}"

# Rename LOCAL_DEFCONFIG to 'defconfig' and move it in WORKDIR
handle_defconfig () {
    if [ -n "${LOCAL_DEFCONFIG}" ] && [ -f "${LOCAL_DEFCONFIG}" ]; then
        cp ${LOCAL_DEFCONFIG} ${WORKDIR}/defconfig
    fi
}
do_unpack[postfuncs] += "handle_defconfig"

# Add in SCR_URI patches and fragments from external path (LOCAL_EXTRA_PATH) if exists
python __anonymous() {
    import os, bb

    dir = d.getVar('LOCAL_EXTRA_PATH', True)

    if dir and os.path.isdir(dir):
        patches = sorted([f for f in os.listdir(dir) if f.endswith('.patch')])
        configs = sorted([f for f in os.listdir(dir) if f.endswith('.cfg')])

        new_files = []

        for patch in patches:
            new_files.append("file://" + patch)

        for config in configs:
            new_files.append("file://" + config)

        if new_files:
            src_uri = d.getVar('SRC_URI', True) or ""
            d.setVar('SRC_URI', src_uri + " " + " ".join(new_files))
}

KERNEL_EXTRA_FEATURES = ""
KERNEL_FEATURES:remove = "cfg/efi.scc"
KERNEL_VERSION_SANITY_SKIP = "1"
KERNEL_DANGLING_FEATURES_WARN_ONLY = "0"
