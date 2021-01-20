do_install_append () {
    # Mount /var directories that must be writable as tmpfs for read-only rootfs
    if ${@bb.utils.contains('DISTRO_FEATURES','redonly-rootfs','false','true',d)}; then
        cat >> ${D}${sysconfdir}/fstab <<EOF

tmpfs                /var/cache           tmpfs      defaults              0  0
tmpfs                /var/yp              tmpfs      defaults              0  0

EOF
    fi
}
