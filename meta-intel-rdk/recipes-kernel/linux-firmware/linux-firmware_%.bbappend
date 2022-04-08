USE_RDK_REPO ?= "false"
RDK_REPO ?= ""
RDK_REPO_REV ?= ""
RDK_REPO_SRC_URI ?= "git://${@d.getVar('RDK_REPO').replace('https://','')};protocol=https;nobranch=1;name=rdk;subpath=rdk/klm;destsuffix=rdk/klm"
SRCREV_rdk = "${RDK_REPO_REV}"

FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"
RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"

SRC_URI_append = " ${@oe.utils.conditional('USE_RDK_REPO', 'false', '${RDK_KLM_ARCHIVE}', '${RDK_REPO_SRC_URI}', d)}"

BB_STRICT_CHECKSUM = "0"

do_install_append () {
    # Remove upstream QAT firmware files and install the specific Axxia KLM ones
    rm -f ${D}${nonarch_base_libdir}/firmware/qat*.bin
    install -m 0644 ${WORKDIR}/rdk/klm/qat/qat/fw/*.bin ${D}${nonarch_base_libdir}/firmware/
}

PACKAGES =+ "${PN}-klm-qat-license ${PN}-klm-qat"

# For INTEL Axxia KLM QAT
LICENSE_${PN}-klm-qat = "Firmware-qat"
LICENSE_${PN}-klm-qat-license = "Firmware-qat"

FILES_${PN}-klm-qat = "${nonarch_base_libdir}/firmware/qat*.bin"
FILES_${PN}-klm-qat-license = "${nonarch_base_libdir}/firmware/LICENCE.qat_firmware"

RDEPENDS_${PN}-klm-qat_append = " ${PN}-klm-qat-license"
