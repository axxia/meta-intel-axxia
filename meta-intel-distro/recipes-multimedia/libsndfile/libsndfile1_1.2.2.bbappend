FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://0001-Include-stdbool.h-instead-of-redefining-bool-true-an.patch"
