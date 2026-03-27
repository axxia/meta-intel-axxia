FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:" 
    
SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		  ' file://0001-Fix-build-with-GCC-15.patch', '', d)}"
