inherit multilib_script

MULTILIB_SCRIPTS = "${PN}:${libexecdir_native}/bats-core/bats \
		    ${PN}:${libexecdir_native}/bats-core/bats-exec-file \
		    ${PN}:${libexecdir_native}/bats-core/bats-exec-test \
		    ${PN}:${libexecdir_native}/bats-core/bats-exec-suite \
		    ${PN}:${libexecdir_native}/bats-core/bats-format-junit \
		    ${PN}:${libexecdir_native}/bats-core/bats-format-pretty \
		    ${PN}:${libexecdir_native}/bats-core/bats-format-tap \
		    ${PN}:${libexecdir_native}/bats-core/bats-format-tap13 \
		    ${PN}:${libexecdir_native}/bats-core/bats-preprocess \
		    "
