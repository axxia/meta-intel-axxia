do_install_append() {
	# Allow root to log in through telnet.  This is a security hole
	# but it is needed for legacy reasons (i.e. testing).

	cat >> ${D}${sysconfdir}/securetty << _EOM

# XXX: allow root to log in through telnet.  Needed for testing.
pts/0
pts/1
pts/2
pts/3
pts/4
pts/5
pts/6
pts/7
pts/8
pts/9

_EOM

}
