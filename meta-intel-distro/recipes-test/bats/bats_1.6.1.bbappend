inherit multilib_script

MULTILIB_SCRIPTS = "${PN}:${libexecdir_native}/bats-core/bats \
		    ${PN}:${libexecdir_native}/bats-core/bats-exec-file \
		    ${PN}:${libexecdir_native}/bats-core/bats-exec-test \
		    "
