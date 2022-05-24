SRC_URI = "git://git.savannah.gnu.org/git/gnulib.git;branch=master"

do_install () {
    install -d ${D}/${datadir}/gnulib
    cp --no-preserve=ownership --recursive ${S}/* ${D}/${datadir}/gnulib/
    cp --no-preserve=ownership --recursive ${S}/.git ${D}/${datadir}/gnulib/
}
