FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://THRIFT-5492-Add-readEnd-to-TBufferedTransport-client-cpp.patch"
