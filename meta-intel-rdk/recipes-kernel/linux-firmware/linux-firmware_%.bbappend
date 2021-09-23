FILESEXTRAPATHS_prepend := "${LAYER_PATH_meta-intel-rdk}/downloads:"

RDK_KLM_ARCHIVE ?= "file://rdk_klm_src.tar.xz"

SRC_URI_append = " ${RDK_KLM_ARCHIVE}"

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
