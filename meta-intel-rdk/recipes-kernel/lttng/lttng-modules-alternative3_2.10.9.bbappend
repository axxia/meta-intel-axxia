require lttng-modules-rdk.inc

# Ensure kernel artifacts are deployed in work-shared
do_compile[depends] += "${KERNEL}:do_deploy"
