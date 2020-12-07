FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " \
	file://0001-Fixed-build-failure-with-glibc-2.30-due-to-dropped-R.patch \
	file://linux_5.x.patch \
	"
