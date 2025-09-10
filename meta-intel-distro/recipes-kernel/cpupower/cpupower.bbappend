TARGET_CC_ARCH += "-fdebug-prefix-map=${STAGING_KERNEL_DIR}=${KERNEL_SRC_PATH}"

do_install:append() {
   if ${@bb.utils.contains('DISTRO_FEATURES', 'sysvinit', 'true', 'false', d)}; then
      rm -rf ${D}${libdir}/systemd ${D}${nonarch_libdir}/systemd
      rmdir --ignore-fail-on-non-empty ${D}${libdir} ${D}${nonarch_libdir} || true
   fi
}

FILES:${PN}:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', \
                       '${libdir}/systemd ${nonarch_libdir}/systemd', '', d)}"
