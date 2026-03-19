# Remove all connman references from RDEPENDS
RDEPENDS:${PN}:remove = "connman-tools connman-tests connman-client"

# Remove gst-exaples and gstreamer with GCC-15
GSTEXAMPLES = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', '', 'gst-examples', d)}"
