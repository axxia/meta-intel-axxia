FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

DEPENDS += "python3-setuptools-native"

RDEPENDS_${PN}-tests =+ "bash"

do_configure_append () {
    # the fetcher is inhibited by the 'inherit kernelsrc', so we do a quick check and
    # copy for a helper script we need
    for p in $(echo ${FILESPATH} | tr ':' '\n'); do
	if [ -e $p/sort-pmuevents-new.py ]; then
	    cp $p/sort-pmuevents-new.py ${S}/sort-pmuevents.py
	fi
    done
}
