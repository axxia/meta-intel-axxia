IES_ENABLE_SHM ?= "true"

# Skip lttng-modules recipes for alternative kernels if meta-intel-distro layer is not used
# or alternative kernels are not supported
# Skip parsing rdk-tools recipe if rdk-userspace feature is not enabled
# Skip parsing linux recipes with private sources if not used in build
BBMASK += "${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', \
		'meta-intel-rdk/recipes-kernel/lttng/lttng-modules-alternative*', '', d)} \
	   ${@bb.utils.contains('BBFILE_COLLECTIONS', 'intel-distro', \
		'', 'meta-intel-rdk/recipes-kernel/lttng/lttng-modules-alternative*', d)} \
	   ${@bb.utils.contains('DISTRO_FEATURES', 'rdk-userspace', \
		'', 'recipes-extended/rdk-tools', d)} \
	   ${@bb.utils.contains('PREFERRED_PROVIDER_virtual/kernel', 'linux-intel-private', \
		'', 'meta-intel-rdk/recipes-kernel/linux/linux-intel-private*', d)} \
	  "
