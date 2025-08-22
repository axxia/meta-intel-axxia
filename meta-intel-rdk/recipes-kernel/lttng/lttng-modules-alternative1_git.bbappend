require ${@oe.utils.conditional('MACHINE', 'intel-axxia-pmr', '', 'lttng-modules-rdk.inc', d)}

# Ensure kernel artifacts are deployed in work-shared
do_compile[depends] += "${KERNEL}:do_deploy"
