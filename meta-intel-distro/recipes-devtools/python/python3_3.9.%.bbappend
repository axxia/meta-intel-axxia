# Overwrite RDEPENDS to fix multilib qa issue
RDEPENDS_${PN}-tkinter = "${@bb.utils.contains('PACKAGECONFIG', 'tk', '${MLPREFIX}tk ${MLPREFIX}tk-lib', '', d)}"
RDEPENDS_${PN}-idle = "${@bb.utils.contains('PACKAGECONFIG', 'tk', '${PN}-tkinter ${MLPREFIX}tcl', '', d)}"
