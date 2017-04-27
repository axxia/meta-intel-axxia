FILESEXTRAPATHS_prepend := "${COREBASE}/meta/recipes-connectivity/${PN}/${PN}:\
${COREBASE}/meta/recipes-connectivity/${PN}/files:"

require recipes-connectivity/${PN}/${PN}_1.3.3.bb

DEPENDS = "libcap libnfsidmap libevent util-linux sqlite3"

SRC_URI = "${KERNELORG_MIRROR}/linux/utils/nfs-utils/${PV}/nfs-utils-${PV}.tar.xz \
           file://0001-configure-Allow-to-explicitly-disable-nfsidmap.patch \
           file://nfs-utils-1.2.3-sm-notify-res_init.patch \
           file://nfsserver \
           file://nfscommon \
           file://nfs-utils.conf \
           file://nfs-server.service \
           file://nfs-mountd.service \
           file://nfs-statd.service \
           file://proc-fs-nfsd.mount \
           file://nfs-utils-Do-not-pass-CFLAGS-to-gcc-while-building.patch \
           file://nfs-utils-debianize-start-statd.patch \
           file://bugfix-adjust-statd-service-name.patch \
"

SRC_URI[md5sum] = "8de676b9ff34b8f9addc1d0800fabdf8"
SRC_URI[sha256sum] = "ff79d70b7b58b2c8f9b798c58721127e82bb96022adc04a5c4cb251630e696b8"

EXTRA_OECONF += "--disable-tirpc \
                 --disable-ipv6"

PACKAGECONFIG = "tcp-wrappers"