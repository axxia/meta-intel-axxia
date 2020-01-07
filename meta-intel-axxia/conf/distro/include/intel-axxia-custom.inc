# Set alternative kernels (different from virtual/kenrel provider)
ALTERNATIVE_KERNELS ?= "\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel', '',          ' linux-intel', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel-rt', '',       ' linux-intel-rt', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel-debug', '',    ' linux-intel-debug', d)}\
${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel',\
	'linux-intel-rt-debug', '', ' linux-intel-rt-debug', d)}\
"
ALTERNATIVE_KERNELS_INSTALL ?= \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','kernel-linux-')}"

ALTERNATIVE_KERNELS_MODULES_INSTALL ?= \
"${@'-modules '.join(d.getVar('ALTERNATIVE_KERNELS_INSTALL')[1:].split(' '))}-modules"

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
