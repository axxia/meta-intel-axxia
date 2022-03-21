SUMMARY = "Apache Thrift"
DESCRIPTION =  "A software framework, for scalable cross-language services development"
HOMEPAGE = "https://thrift.apache.org/"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=394465e125cffc0f133695ed43f14047 \
                    file://NOTICE;md5=42748ae4646b45fbfa5182807321fb6c"

DEPENDS = "thrift-native flex-native bison-native"

SRC_URI = "https://archive.apache.org/dist/${BPN}/${PV}/${BPN}-${PV}.tar.gz"

SRC_URI[md5sum] = "0be59730ebce071eceaf6bfdb8d3a20e"
SRC_URI[sha256sum] = "c4ad38b6cb4a3498310d405a91fef37b9a8e79a50cd0968148ee2524d2fa60c2"

BBCLASSEXTEND = "native nativesdk"

inherit pkgconfig autotools python3native

B = "${S}"

REMOVE_LIBTOOL_LA = "0"

EXTRA_OECONF += "--enable-shared \
		 --enable-libs \
		 --disable-tests \
		 --disable-tutorial \
		 --disable-plugin \
		 --with-cpp \
		"

PACKAGECONFIG ??= "libevent openssl boost glib static"
PACKAGECONFIG[libevent] = "--with-libevent=${STAGING_EXECPREFIXDIR},--without-libevent,libevent,"
PACKAGECONFIG[openssl] = "--with-openssl=${STAGING_EXECPREFIXDIR},--without-openssl,openssl,"
PACKAGECONFIG[boost] = "--with-boost=${STAGING_EXECPREFIXDIR},--without-boost,boost,"
PACKAGECONFIG[python] = "--with-python,--without-python,python3,"
PACKAGECONFIG[glib] = "--with-c_glib,--without-c_glib,glib-2.0,"
PACKAGECONFIG[static] = "--enable-static,--disable-static,,"

do_configure() {
	# preserve original config
	cp config.h config.h.orig
	
	${S}/bootstrap.sh
	oe_runconf

	# use original config
	cp config.h.orig config.h
	cp config.h lib/cpp/src/thrift/config.h
	cp config.h lib/c_glib/src/thrift/config.h

	# do not build tests from lib/c_glib; force it in Makefiles  
	# because --disable-tests option is not skipping this for c_glib
	sed -i "s/SUBDIRS = . test/SUBDIRS = ./g" lib/c_glib/Makefile.*
}

do_install_append () {
	ln -sf thrift ${D}/${bindir}/thrift-compiler
}

LEAD_SONAME = "libthrift-${PV}.so"

# thrift packages
PACKAGES =+ "${PN}-compiler lib${BPN}z lib${BPN}nb lib${BPN}-c-glib lib${BPN}"
FILES_lib${BPN}z = "${libdir}/libthriftz-*.so"
FILES_lib${BPN}nb = "${libdir}/libthriftnb-*.so"
FILES_lib${BPN}-c-glib = "${libdir}/libthrift_c_glib.so.0.*"
FILES_lib${BPN} = "${libdir}/libthrift-*.so"
FILES_${PN}-dev += "${libdir}/*.so*"
FILES_${PN}-compiler = "${bindir}/*"

# The thrift packages just pulls in some default dependencies but is otherwise empty
RRECOMMENDS_${PN} = "${PN}-compiler lib${BPN}"
ALLOW_EMPTY_${PN} = "1"
RRECOMMENDS_${PN}_class-native = ""
RRECOMMENDS_${PN}_class-nativesdk = ""
