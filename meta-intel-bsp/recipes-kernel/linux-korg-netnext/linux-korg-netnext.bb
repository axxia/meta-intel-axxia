require recipes-kernel/linux/linux-intel.inc
require recipes-kernel/linux/linux-axxia.inc

FILESEXTRAPATHS:prepend := "${@oe.utils.conditional('KORG_NETNEXT_EXTRA_PATH', '', '', '${KORG_NETNEXT_EXTRA_PATH}:', d)}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/netdev/net-next.git;protocol=https;name=machine;branch=${KBRANCH} \
           ${@oe.utils.conditional('KORG_NETNEXT_CONFIG', 'frags', '${KERNEL_CONFIG_URI}', 'file://${KORG_NETNEXT_CONFIG}', d)}"

KBRANCH = "main"
KMETA_BRANCH = "yocto-6.16"

LINUX_VERSION = "${@d.getVar('KBRANCH').replace('/','.')}.${@d.getVar('SRCREV_machine')[:8]}"
LINUX_VERSION_EXTENSION = "-korg-netnext-${LINUX_KERNEL_TYPE}"

KORG_NETNEXT_REVISION ?= "fa582ca7e187a15e772e6a72fe035f649b387a60"
SRCREV_machine = "${KORG_NETNEXT_REVISION}"
SRCREV_meta = "f5fdef1633ed82ffa1e8103c7802e61b319d809c"

KORG_NETNEXT_CONFIG ?= "${@oe.utils.conditional('KORG_NETNEXT_EXTRA_PATH', '', 'frags', 'defconfig', d)}"

KCONFIG_MODE = "alldefconfig"
KMETA = "${@oe.utils.conditional('KORG_NETNEXT_CONFIG', 'frags', 'kernel-meta', '', d)}"
INTEL_AXXIA_FRAGS = "${@oe.utils.conditional('KORG_NETNEXT_CONFIG', 'frags', 'file://common.scc file://${CPU}.scc ', '', d)}"

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
KERNEL_EXTRA_FEATURES = "${@oe.utils.conditional('KORG_NETNEXT_CONFIG', 'frags', '${KERNEL_EXTRA_FEATURES_FRAGS}', '', d)}"
KERNEL_FEATURES:remove = "${@oe.utils.conditional('KORG_NETNEXT_CONFIG', 'frags', '', 'cfg/efi.scc cfg/virtio.scc', d)}"
KERNEL_EXTRA_FEATURES:remove = "features/debug/debug-kernel.scc"

# Add in SRC_URI patches and fragments from external path (KORG_NETNEXT_EXTRA_PATH) if exists
KORG_NETNEXT_EXTRA_PATH ?= ""

python __anonymous() {
    import os, bb

    dir = d.getVar('KORG_NETNEXT_EXTRA_PATH', True)

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
