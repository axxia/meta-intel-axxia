FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://0001-add-new-memory-device-types-from-SMBIOS-spec-3.4.0.patch"
