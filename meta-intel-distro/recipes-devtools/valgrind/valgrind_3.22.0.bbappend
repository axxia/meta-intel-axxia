FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

GCC15_PATCHES ?= "file://0001-helgrind-tests-tc17_sembar.c-Remove-bool-typedef.patch \
		  file://0001-drd-tests-swapcontext.c-Rename-typedef-struct-thread.patch \
		  file://0001-none-tests-bug234814.c-sa_handler-take-an-int-as-arg.patch" 

SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', ' ${GCC15_PATCHES}', '', d)}"
