do_install:append() {
    # Remove OE-generated serial getty lines that pass baud
    # into /bin/start_getty.
    sed -i '\#/start_getty#d' ${D}${sysconfdir}/inittab

    CONSOLES="${SERIAL_CONSOLES}"
    for s in $CONSOLES; do
        device=$(echo "$s" | cut -d\; -f2)
        label=$(echo "$device" | sed -e 's/tty//' | tail --bytes=5)

        echo "$label:12345:respawn:${sbindir}/ttyrun $device ${base_sbindir}/getty -L $device vt102" >> ${D}${sysconfdir}/inittab
    done
}
