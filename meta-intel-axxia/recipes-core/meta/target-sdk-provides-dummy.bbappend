DUMMYPROVIDES_append = "\
	perl-module-config \
	perl-module-file-temp \
	perl-module-overload \
	perl-module-warnings \
	perl-module-warnings-register \
"

DUMMYPROVIDES_remove = "\
	${@bb.utils.contains('DISTRO_FEATURES', 'multilib', \
	'bash /bin/sh /bin/bash', '', d)}"
