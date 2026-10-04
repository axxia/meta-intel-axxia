# Set default alternative kernel to the debug variant of the current kernel provider.
# linux-local and linux-korg have no debug variant.
ALTERNATIVE_KERNELS ?= "${@'' if d.getVar('PREFERRED_PROVIDER_virtual/kernel') in \
    ['linux-local', 'linux-korg'] else \
    ' ' + d.getVar('PREFERRED_PROVIDER_virtual/kernel') + '-debug'}"

ALTERNATIVE_KERNELS_INSTALL ?= \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','altkernel-linux-')}"

ALTERNATIVE_KERNELS_MODULES_INSTALL ?= \
"${@'-modules '.join(d.getVar('ALTERNATIVE_KERNELS_INSTALL').split())}-modules"

ALTERNATIVE_KERNELS_LTTNG_MODULES ?= \
"${@' '.join('lttng-modules-' + k for k in d.getVar('ALTERNATIVE_KERNELS').split())}"

ALTERNATIVE_KERNELS_BOOT_LABELS = \
"${@d.getVar('ALTERNATIVE_KERNELS').replace('linux-','boot-linux-')}"

ALTERNATIVE_KERNELS_CLEAN_TASK = \
"${@':do_clean '.join(d.getVar('ALTERNATIVE_KERNELS').split())}:do_clean"
ALTERNATIVE_KERNELS_CLEANSSTATE_TASK = \
"${@':do_cleansstate '.join(d.getVar('ALTERNATIVE_KERNELS').split())}:do_cleansstate"
ALTERNATIVE_KERNELS_DEPLOY_TASK = \
"${@':do_deploy '.join(d.getVar('ALTERNATIVE_KERNELS').split())}:do_deploy"
ALTERNATIVE_KERNELS_CLEAN = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_CLEAN_TASK}', d)}"
ALTERNATIVE_KERNELS_CLEANSSTATE = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_CLEANSSTATE_TASK}', d)}"
ALTERNATIVE_KERNELS_DEPLOY = \
"${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', '${ALTERNATIVE_KERNELS_DEPLOY_TASK}', d)}"

