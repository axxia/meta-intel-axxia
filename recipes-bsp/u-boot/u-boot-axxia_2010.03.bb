require u-boot-axxia.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b"

UBOOT_MACHINE_axxiapowerpc = "ACP344xV2_stage3_config"

SPL_BINARY = ""

SRCREV = "lsi_axxia_u-boot_4.8.1.103"

PV = "2010.03+${SRCREV}"
PR = "r1"

SRC_URI = "git://github.com/axxia/axxia_u-boot.git"
