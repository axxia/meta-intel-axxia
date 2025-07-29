TARGET_CC_ARCH += "-fdebug-prefix-map=${STAGING_KERNEL_DIR}=${KERNEL_SRC_PATH}"

do_install:append() {
   if ${@bb.utils.contains('DISTRO_FEATURES', 'sysvinit', 'true', 'false', d)}; then
      rm -f ${D}${systemd_system_unitdir}/cpupower.service
   fi
}

FILES:${PN} += "${@bb.utils.contains('DISTRO_FEATURES', 'systemd', \
               '${systemd_system_unitdir}/cpupower.service', '', d)}"
