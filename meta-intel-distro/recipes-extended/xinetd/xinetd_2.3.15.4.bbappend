PACKAGECONFIG:remove = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', 'tcp-wrappers', '', d)}"

# GCC 15 is coming with C23 as default and code is not ready for C23
CFLAGS += "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', '-std=gnu17', '', d)}"
