FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://0001-src-secure_allocator.hpp-define-missing-rebind-type.patch"
