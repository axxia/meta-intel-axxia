SUMMARY = "Read only rootfs with overlay init script"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
DEPENDS = "virtual/kernel"
SRC_URI = "file://init-readonly-rootfs-overlay-boot.sh"

S = "${WORKDIR}"

do_install() {
        install -m 0755 ${WORKDIR}/init-readonly-rootfs-overlay-boot.sh ${D}/init-readonly-overlay
        install -d "${D}/media/rfs/ro"
        install -d "${D}/media/rfs/rw"
}

FILES:${PN} += " /init-readonly-overlay /media/rfs"

# Due to kernel dependency
PACKAGE_ARCH = "${MACHINE_ARCH}"

# Force to install in /media
INSANE_SKIP:${PN} = "empty-dirs"
