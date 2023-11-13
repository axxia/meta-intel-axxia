do_install:append () {
   # enable clientid instead duid
   sed -i 's/#clientid/clientid/' ${D}${sysconfdir}/dhcpcd.conf
   sed -i 's/duid/#duid/' ${D}${sysconfdir}/dhcpcd.conf
}
