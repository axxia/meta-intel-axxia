IMAGE_INSTALL_append = " \
linux-firmware-klm-qat \
${PREFERRED_PROVIDER_virtual/kernel}-kernel-headers \
${@bb.utils.contains('DISTRO_FEATURES', 'rdk-userspace', \
		     'rdk-tools rdk-tools-dev rdk-firmware', '', d)} \
"
