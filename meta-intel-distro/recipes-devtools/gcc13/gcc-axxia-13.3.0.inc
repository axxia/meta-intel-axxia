FILESEXTRAPATHS:prepend := "${THISDIR}/gcc:"

SRC_URI:append = " file://0001-Guard-broadcast-from-imm-under-tune-bcst_from_imm-di.patch"
