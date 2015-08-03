#
# Copyright (C) 2007 OpenedHand Ltd.
#

SUMMARY = "Large File System for Testing"
DESCRIPTION = "The Large set of packages required for testing the system"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r10"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

#
# Set by the machine configuration with packages essential for device bootup
#
MACHINE_ESSENTIAL_EXTRA_RDEPENDS ?= ""
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS ?= ""

# For backwards compatibility after rename
RPROVIDES_${PN} = "task-core-boot"
RREPLACES_${PN} = "task-core-boot"
RCONFLICTS_${PN} = "task-core-boot"

# Distro can override the following VIRTUAL-RUNTIME providers:
#VIRTUAL-RUNTIME_dev_manager ?= "udev"
VIRTUAL-RUNTIME_dev_manager ?= ""
#VIRTUAL-RUNTIME_login_manager ?= "tinylogin" # tinylogin depreciated
# busybox now has tinylogin feature
VIRTUAL-RUNTIME_login_manager ?= "busybox"
VIRTUAL-RUNTIME_init_manager ?= "sysvinit"
VIRTUAL-RUNTIME_initscripts ?= "initscripts"
#VIRTUAL-RUNTIME_initscripts ?= ""
VIRTUAL-RUNTIME_keymaps ?= "keymaps"

#    busybox \
#    ${@base_contains("MACHINE_FEATURES", "rtc", "busybox-hwclock", "", d)} \
#    ${VIRTUAL-RUNTIME_initscripts} \
#    ${@base_contains("MACHINE_FEATURES", "keyboard", "${VIRTUAL-RUNTIME_keymaps}", "", d)} \
#    modutils-initscripts \
#    netbase \
#    ${VIRTUAL-RUNTIME_login_manager} \
#    ${VIRTUAL-RUNTIME_init_manager} \
#    ${VIRTUAL-RUNTIME_dev_manager} \
#    ${VIRTUAL-RUNTIME_update-alternatives} \
#    ${MACHINE_ESSENTIAL_EXTRA_RDEPENDS}"

RDEPENDS_${PN} = "\
    base-files \
    base-passwd \
    acl \
    attr \
    bash \
    coreutils \
    mktemp \
    ncurses \
    procps \
    sysvinit \
    busybox \
    util-linux \
    gdbserver \
    grep \
    sed \
    kmod \
    initscripts \
    less \
    iputils \
    libevent \
    tcl \
    libxdmcp \
    libpcap \
    libdaemon \
    libnfsidmap \
    libcheck \
    gmp \
    ethtool \
    libsndfile1 \
    unzip \
    python \
    db \
    cpio \
    ocf-linux \
    lzo \
    alsa-state \
    shadow \
    util-linux \
    apmd \
    libsm \
    libtirpc \
    dbus \
    psmisc \
    bison \
    net-tools \
    opkg \
    man-pages \
    expat \
    findutils \
    parted \
    rpcbind \
    ed \
    popt \
    stat \
    udev \
    sed \
    setserial \
    tcp-wrappers \
    mdadm \
    bluez4 \
    groff \
    iptables \
    elfutils \
    libgpg-error \
    libice \
    libnss-mdns \
    icu \
    msmtp \
    mtd-utils \
    bc \
    wget \
    libgcrypt \
    openssh \
    update-rc.d \
    acl \
    gnutls \
    libogg \
    sysklogd \
    alsa-utils \
    libusb1 \
    bluez-hcidump \
    ppp \
    libxcb \
    procps \
    watchdog \
    gawk \
    rpm \
    readline \
    zip \
    cronie \
    pkgconfig \
    perl \
    tzdata \
    bash \
    libaio \
    libpcre \
    netbase \
    libsamplerate0 \
    sudo \
    lrzsz \
    glib-2.0 \
    shadow-securetty \
    hdparm \
    flac \
    sysfsutils \
    libpam \
    beecrypt \
    grep \
    task-base \
    libnl \
    zlib \
    libtasn1 \
    irda-utils \
    hostap-utils \
    pciutils \
    avahi \
    cracklib \
    ossp-uuid \
    tar \
    flex \
    util-macros \
    openssl \
    logrotate \
    diffutils \
    at \
    file \
    udev-extraconf \
    curl \
    dbus-glib \
    libusb-compat \
    bzip2 \
    opkg-arch-config \
    alsa-lib \
    gettext \
    bind \
    which \
    sqlite3 \
    libcap \
    libxau \
    wireless-tools \
    modutils-initscripts \
    gzip \
    libtool \
    nfs-utils \
    nfs-utils-client \
    libffi \
    wpa-supplicant \
    man \
    strace \
    usbutils \
    e2fsprogs \
    module-init-tools \
    time \
    iproute2 \
    quota \
    yp-tools \
    ypbind-mt \    
    inetutils \
    autofs \
    "

RRECOMMENDS_${PN} = "\
    ${MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS}"
