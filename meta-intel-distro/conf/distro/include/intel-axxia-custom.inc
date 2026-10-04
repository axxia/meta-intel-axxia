# Set alternative kernels (different from virtual/kernel provider)
# Add the debug variant of the current kernel provider as alternative.
# linux-local and linux-korg have no debug variant.
ALTERNATIVE_KERNELS ?= "${@'' if d.getVar('PREFERRED_PROVIDER_virtual/kernel') in \
    ['linux-local', 'linux-korg'] else \
    ' ' + d.getVar('PREFERRED_PROVIDER_virtual/kernel') + '-debug'}"

ALTERNATIVE_KERNELS_INSTALL ?= \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','altkernel-linux-')}"

ALTERNATIVE_KERNELS_MODULES_INSTALL ?= \
"${@'-modules '.join(d.getVar('ALTERNATIVE_KERNELS_INSTALL')[1:].split(' '))}-modules"

ALTERNATIVE_KERNELS_LTTNG_MODULES ?= \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','lttng-modules-linux-')}"

ALTERNATIVE_KERNELS_BOOT_LABELS = \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','boot-linux-')}"

ALTERNATIVE_KERNELS_CLEAN_TASK = \
"${@':do_clean '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}:do_clean"
ALTERNATIVE_KERNELS_CLEANSSTATE_TASK = \
"${@':do_cleansstate '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}:do_cleansstate"
ALTERNATIVE_KERNELS_DEPLOY_TASK = \
"${@':do_deploy '.join(d.getVar('ALTERNATIVE_KERNELS')[1:].split(' '))}:do_deploy"
ALTERNATIVE_KERNELS_CLEAN = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_CLEAN_TASK}', d)}"
ALTERNATIVE_KERNELS_CLEANSSTATE = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_CLEANSSTATE_TASK}', d)}"
ALTERNATIVE_KERNELS_DEPLOY = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_DEPLOY_TASK}', d)}"

