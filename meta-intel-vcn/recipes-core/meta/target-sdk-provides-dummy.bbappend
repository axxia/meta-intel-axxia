DUMMYPROVIDES_remove = "\
	${@bb.utils.contains('DISTRO_FEATURES', 'multilib', \
	'bash /bin/sh /bin/bash', '', d)}"
