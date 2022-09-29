# Replace libdir with base_libdir in libelf.pc to fix linker from a multilib SDK
# when searching for libc libraries (libc.so.6 and libc_nonshared.a)
do_install:append() {
	sed -i "s#libdir=${libdir}#libdir=${base_libdir}#g" ${D}${libdir}/pkgconfig/libelf.pc
}
