TARGET_CC_ARCH += "-fdebug-prefix-map=${STAGING_KERNEL_DIR}=${KERNEL_SRC_PATH}"

do_install:append() {
   if ${@bb.utils.contains('DISTRO_FEATURES', 'sysvinit', 'true', 'false', d)}; then
      rm -rf ${D}${libdir}/systemd
   fi
}

FILES:${PN}:append = " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', '${libdir}/systemd', '', d)}"
