require lttng-modules-rdk.inc

# Ensure kernel artifacts are deployed in work-shared
do_compile[depends] += "${PREFERRED_PROVIDER_virtual/kernel}:do_deploy"
