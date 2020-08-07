do_install_append() {
	(
	cd $S
	# copy all headers from RDK KLM modules
	cp --parents $(find drivers/staging/intel -type f -name "*.h") \
		     $kerneldir/build 2>/dev/null || :
	)
}
