FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " \
    file://power_button \
    file://power_button.sh \
"

do_install:append() {
    install -d ${D}${sysconfdir}/acpi/events
    install -m 0644 ${UNPACKDIR}/power_button ${D}${sysconfdir}/acpi/events/power_button
    install -m 0755 ${UNPACKDIR}/power_button.sh ${D}${sysconfdir}/acpi/power_button.sh
}
