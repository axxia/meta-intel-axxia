FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:" 
    
SRC_URI:append = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', \
		  ' file://0001-ltp-pan-fix-wait_handler-declaration.patch', '', d)}"
