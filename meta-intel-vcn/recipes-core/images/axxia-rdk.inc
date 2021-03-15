IMAGE_INSTALL_append = " \
${PREFERRED_PROVIDER_virtual/kernel}-kernel-headers \
${@bb.utils.contains('DISTRO_FEATURES', 'rdk-userspace', \
		     'rdk-tools rdk-tools-dev', '', d)} \
"
