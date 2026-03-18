PACKAGECONFIG:remove = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc15', 'tcp-wrappers', '', d)}"
