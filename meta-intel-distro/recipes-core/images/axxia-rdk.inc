IMAGE_INSTALL:append = " \
    ${@oe.utils.conditional('MACHINE', 'intel-axxia-pmr', '', \
			    'linux-firmware-klm-qat ${PREFERRED_PROVIDER_virtual/kernel}-kernel-headers', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'rdk-userspace', \
			 'rdk-tools rdk-tools-dev rdk-firmware', '', d)} \
    "
