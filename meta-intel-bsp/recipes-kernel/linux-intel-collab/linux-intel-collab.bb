require recipes-kernel/linux/linux-intel.inc
require recipes-kernel/linux/linux-axxia.inc

FILESEXTRAPATHS:prepend := "${@oe.utils.conditional('INTEL_COLLAB_EXTRA_PATH', '', '', '${INTEL_COLLAB_EXTRA_PATH}:', d)}"

SRC_URI = "git://github.com/intel-collab/os.linux.kernelsource.platform-enablement.git;protocol=https;name=machine;branch=${KBRANCH} \
           ${@oe.utils.conditional('INTEL_COLLAB_CONFIG', 'frags', '${KERNEL_CONFIG_URI}', 'file://${INTEL_COLLAB_CONFIG}', d)}"

KBRANCH = "6.18/svl"
KMETA_BRANCH = "yocto-6.18"

LINUX_VERSION = "${@d.getVar('KBRANCH').replace('/','.')}.${@d.getVar('SRCREV_machine')[:8]}"
LINUX_VERSION_EXTENSION = "-intel-collab-${LINUX_KERNEL_TYPE}"

INTEL_COLLAB_REVISION ?= "a60894fb2e3e93e7b2b943027d79343a4c630033"
SRCREV_machine = "${INTEL_COLLAB_REVISION}"
SRCREV_meta = "9e9d8b1f9128b07d938b8b7d5921aeb3ddf907a1"

INTEL_COLLAB_CONFIG ?= "${@oe.utils.conditional('INTEL_COLLAB_EXTRA_PATH', '', 'frags', 'defconfig', d)}"

KCONFIG_MODE = "alldefconfig"
KMETA = "${@oe.utils.conditional('INTEL_COLLAB_CONFIG', 'frags', 'kernel-meta', '', d)}"
INTEL_AXXIA_FRAGS = "${@oe.utils.conditional('INTEL_COLLAB_CONFIG', 'frags', 'file://common.scc file://${CPU}.scc ', '', d)}"

COMMON_PATCHES = " \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
"

PMR_PATCHES = " \
"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

KERNEL_VERSION_SANITY_SKIP = "1"

# Functionality flags
KERNEL_EXTRA_FEATURES_FRAGS ?= "features/netfilter/netfilter.scc features/security/security.scc"
KERNEL_EXTRA_FEATURES = "${@oe.utils.conditional('INTEL_COLLAB_CONFIG', 'frags', '${KERNEL_EXTRA_FEATURES_FRAGS}', '', d)}"
KERNEL_FEATURES:remove = "${@oe.utils.conditional('INTEL_COLLAB_CONFIG', 'frags', '', 'cfg/efi.scc cfg/virtio.scc', d)}"
KERNEL_EXTRA_FEATURES:remove = "features/debug/debug-kernel.scc"

# Add in SRC_URI patches and fragments from external path (INTEL_COLLAB_EXTRA_PATH) if exists
INTEL_COLLAB_EXTRA_PATH ?= ""

python __anonymous() {
    import os, bb

    dir = d.getVar('INTEL_COLLAB_EXTRA_PATH', True)

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

# External patches from INTEL_COLLAB_EXTRA_PATH lack Upstream-Status headers
ERROR_QA:remove = "${@oe.utils.conditional('INTEL_COLLAB_EXTRA_PATH', '', '', 'patch-status', d)}"
WARN_QA:remove = "${@oe.utils.conditional('INTEL_COLLAB_EXTRA_PATH', '', '', 'patch-status', d)}"
