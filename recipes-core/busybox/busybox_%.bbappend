FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
	    file://enable_tftp_blocksize_feature.cfg \
           "
