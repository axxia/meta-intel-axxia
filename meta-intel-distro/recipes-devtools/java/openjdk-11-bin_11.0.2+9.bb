SUMMARY = "Open JDK Binaries"
HOMEPAGE = "https://jdk.java.net/11/"
LICENSE = "GPL-2.0-with-classpath-exception"
LIC_FILES_CHKSUM = "file://legal/java.base/LICENSE;md5=3e0b59f8fac05c3c03d4a26bbda13f8f"

COMPATIBLE_HOST = "x86_64.*-linux"
# Binaries are linked with glibc
COMPATIBLE_HOST:libc-musl = "null"

JAVA_ARCH:x86-64 = "x64"

# Convert PV to forms needed to download the tarball
PV_MAJOR = "${@d.getVar('PV').split('.')[0]}"
PV_MAIN = "${@d.getVar('PV').split('+')[0]}"
PV_BUILD = "${@d.getVar('PV').split('+')[1]}"

SRC_URI = "https://download.java.net/java/GA/jdk${PV_MAJOR}/${PV_BUILD}/GPL/openjdk-${PV_MAIN}_linux-${JAVA_ARCH}_bin.tar.gz"
SRC_URI[sha256sum] = "99be79935354f5c0df1ad293620ea36d13f48ec3ea870c838f20c504c9668b57"

S = "${WORKDIR}/jdk-${PV_MAIN}"

inherit update-alternatives

# Disable stuff not needed for packaging binaries
INHIBIT_DEFAULT_DEPS = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
EXCLUDE_FROM_SHLIBS = "1"
do_patch[noexec] = "1"
do_configure[noexec] = "1"
do_compile[noexec] = "1"

JAVA_HOME = "${libdir}/jvm/${BPN}"

ALTERNATIVE_PRIORITY = "100"
ALTERNATIVE:${PN} = "java javac keytool"

ALTERNATIVE_LINK_NAME[java] = "${bindir}/java"
ALTERNATIVE_TARGET[java] = "${JAVA_HOME}/bin/java"

ALTERNATIVE_LINK_NAME[javac] = "${bindir}/javac"
ALTERNATIVE_TARGET[javac] = "${JAVA_HOME}/bin/javac"

ALTERNATIVE_LINK_NAME[keytool] = "${bindir}/keytool"
ALTERNATIVE_TARGET[keytool] = "${JAVA_HOME}/bin/keytool"

MULTILIB = "${@bb.utils.contains('DISTRO_FEATURES', 'multilib', 'yes', '', d)}"

do_install() {
    install -d ${D}${JAVA_HOME}
    cp -r ${S}/* ${D}${JAVA_HOME}

    # The x86-64 binaries assume libraries are in /lib64, but a typical pure 64-bit
    # Yocto image puts them in /lib. If not building a multilib image, add a
    # symlink from /lib64 to /lib.
    if [ -z "${MULTILIB}" ]; then
        ln -s /lib ${D}/lib64
    fi
}

FILES:${PN} = " \
    ${JAVA_HOME} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'multilib', '', '/lib64', d)} \
"

RDEPENDS:${PN} = " \
    alsa-lib \
    freetype \
    glibc \
    glibc-thread-db \
    libx11 \
    libxext \
    libxi \
    libxrender \
    libxtst \
    zlib \
"

# Ignore "doesn't have GNU_HASH (didn't pass LDFLAGS?)" errors
INSANE_SKIP:${PN} += "ldflags"
