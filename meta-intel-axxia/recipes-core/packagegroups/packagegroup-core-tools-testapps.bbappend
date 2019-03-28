# Overwrite RDEPENDS to remove all connman subpackages
RDEPENDS_${PN} = "\
    blktool \
    lrzsz \
    ${KEXECTOOLS} \
    alsa-utils-amixer \
    alsa-utils-aplay \
    ltp \
    ${@bb.utils.contains('DISTRO_FEATURES', 'x11', "${X11TOOLS}", "", d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'x11 opengl', "${X11GLTOOLS}", "", d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', '3g', "${3GTOOLS}", "", d)} \
    "
