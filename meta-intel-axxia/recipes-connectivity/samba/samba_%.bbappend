do_install_append() {
    # Limit interfaces to serve SMB requests only to eth0 
    sed -i "/interfaces =/a\interfaces = eth0 lo\nbind interfaces only = yes" \
           ${D}${sysconfdir}/samba/smb.conf
}
