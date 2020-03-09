# Set alternative kernels (different from virtual/kernel provider)
INTEL_ALTERNATIVE_KERNELS ?= "\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel', '',          ' linux-intel', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel-rt', '',       ' linux-intel-rt', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel-debug', '',    ' linux-intel-debug', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel-rt-debug', '', ' linux-intel-rt-debug', d)}\
"

YOCTO_ALTERNATIVE_KERNELS ?= "\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-yocto', '',          ' linux-yocto', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-yocto-rt', '',       ' linux-yocto-rt', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-yocto-debug', '',    ' linux-yocto-debug', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-yocto-rt-debug', '', ' linux-yocto-rt-debug', d)}\
"

ALTERNATIVE_KERNELS ?= \
"${${@''.join(d.getVar('PREFERRED_PROVIDER_virtual/kernel').upper()\
	.split('-')[1:2])}_ALTERNATIVE_KERNELS}"

ALTERNATIVE_KERNELS_INSTALL ?= \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','kernel-linux-')}"

ALTERNATIVE_KERNELS_MODULES_INSTALL ?= \
"${@'-modules '.join(d.getVar('ALTERNATIVE_KERNELS_INSTALL')[1:].split(' '))}-modules"

ALTERNATIVE_KERNELS_LTTNG_MODULES ?= \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','lttng-modules-linux-')}"

ALTERNATIVE_KERNELS_CLEAN_TASK = \
"${@':do_clean '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}:do_clean"
ALTERNATIVE_KERNELS_CLEANSSTATE_TASK = \
"${@':do_cleansstate '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}:do_cleansstate"
ALTERNATIVE_KERNELS_CLEAN = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_CLEAN_TASK}', d)}"
ALTERNATIVE_KERNELS_CLEANSSTATE = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_CLEANSSTATE_TASK}', d)}"

# Fix multilib install file conflicts
ALTERNATIVE_PRIORITY_libtool = "20"
ALTERNATIVE_PRIORITY_lib32-libtool = "10"

ALTERNATIVE_PRIORITY_icu-dev = "20"
ALTERNATIVE_PRIORITY_lib32-icu-dev = "10"

ALTERNATIVE_PRIORITY_gobject-introspection = "20"
ALTERNATIVE_PRIORITY_lib32-gobject-introspection = "10"

ALTERNATIVE_PRIORITY_python3-dev = "90"
ALTERNATIVE_PRIORITY_lib32-python3-dev = "80"

ALTERNATIVE_PRIORITY_libgpg-error-dev = "20"
ALTERNATIVE_PRIORITY_lib32-libgpg-error-dev = "10"
