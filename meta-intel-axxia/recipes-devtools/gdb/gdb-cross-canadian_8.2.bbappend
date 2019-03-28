DEPENDS = "nativesdk-ncurses nativesdk-expat nativesdk-gettext \
	   virtual/${HOST_PREFIX}gcc-crosssdk virtual/${HOST_PREFIX}binutils-crosssdk \
	   ${@bb.utils.contains('DISTRO_FEATURES', 'gcc9', \
			'virtual/nativesdk-libc', \
			'virtual/nativesdk-${HOST_PREFIX}libc-for-gcc', d)}"

