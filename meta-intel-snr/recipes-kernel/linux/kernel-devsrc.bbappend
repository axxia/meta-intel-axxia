do_install_append() {
    # enforce all scripts to use /usr/bin/awk
    cd ${D} || true
    ( for i in `grep -srI "\!/bin/awk" | cut -d":" -f1 ` ; do sed -i -e "s#\!/bin/awk#\!/usr/bin/env awk#g" $i ; done ) || true
}
