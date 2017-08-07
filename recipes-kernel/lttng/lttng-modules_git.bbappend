SRCREV = "f783d4272d18c53c517cbefcffa783dceb0e0dd7"
PV = "2.8.3+git${SRCPV}"

SRC_URI = "git://git.lttng.org/lttng-modules.git;branch=stable-2.9 \
           file://Makefile-Do-not-fail-if-CONFIG_TRACEPOINTS-is-not-en.patch"
