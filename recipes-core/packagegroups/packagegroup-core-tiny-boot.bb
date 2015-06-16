#
# Copyright (C) 2007 OpenedHand Ltd.
#

SUMMARY = "Minimal boot requirements"
DESCRIPTION = "The minimal set of packages required to boot the system"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r10"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

#
# Set by the machine configuration with packages essential for device bootup
#
MACHINE_ESSENTIAL_EXTRA_RDEPENDS ?= ""
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS ?= ""

# For backwards compatibility after rename
RPROVIDES_${PN} = "task-core-boot"
RREPLACES_${PN} = "task-core-boot"
RCONFLICTS_${PN} = "task-core-boot"

# Distro can override the following VIRTUAL-RUNTIME providers:
#VIRTUAL-RUNTIME_dev_manager ?= "udev"
VIRTUAL-RUNTIME_dev_manager ?= ""
VIRTUAL-RUNTIME_login_manager ?= "tinylogin"
VIRTUAL-RUNTIME_init_manager ?= "sysvinit"
VIRTUAL-RUNTIME_initscripts ?= "initscripts"
#VIRTUAL-RUNTIME_initscripts ?= ""
VIRTUAL-RUNTIME_keymaps ?= "keymaps"

#    busybox \
#    ${@base_contains("MACHINE_FEATURES", "rtc", "busybox-hwclock", "", d)} \
#    ${VIRTUAL-RUNTIME_initscripts} \
#    ${@base_contains("MACHINE_FEATURES", "keyboard", "${VIRTUAL-RUNTIME_keymaps}", "", d)} \
#    modutils-initscripts \
#    netbase \
#    ${VIRTUAL-RUNTIME_login_manager} \
#    ${VIRTUAL-RUNTIME_init_manager} \
#    ${VIRTUAL-RUNTIME_dev_manager} \
#    ${VIRTUAL-RUNTIME_update-alternatives} \
#    ${MACHINE_ESSENTIAL_EXTRA_RDEPENDS}"

RDEPENDS_${PN} = "\
    base-files \
    base-passwd \
    acl \
    attr \
    bash \
    coreutils \
    mktemp \
    ncurses \
    procps \
    sysvinit \
    tinylogin \
    util-linux \
    gdbserver \
    grep \
    sed \
    kmod \
    initscripts \
    "

RRECOMMENDS_${PN} = "\
    ${MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS}"
