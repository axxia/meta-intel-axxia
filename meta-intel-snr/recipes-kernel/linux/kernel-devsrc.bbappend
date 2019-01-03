do_install_append() {
    cd ${S}
    # copy all Kbuild and *.mk files for "clean" target
    cp --parents $(find  -type f -name "Kbuild*" -o -name "*.mk") $kerneldir/build
    # copy removed Makefile from documentation dir for "clean" target
    cp -a --parents Documentation/Makefile $kerneldir/build/

    # copy required headers for out-of-tree modules build
    cd ${B}
    cp --parents $(find  -type f -name "unistd_*.h") $kerneldir/build

    # enforce all scripts to use /usr/bin/awk
    cd ${D} || true
    ( for i in `grep -srI "\!/bin/awk" | cut -d":" -f1 ` ; do sed -i -e "s#\!/bin/awk#\!/usr/bin/env awk#g" $i ; done ) || true

    chown -R root:root ${D}    
}
