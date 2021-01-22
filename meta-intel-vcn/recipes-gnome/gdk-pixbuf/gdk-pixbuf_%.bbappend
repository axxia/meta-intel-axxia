# Because qemu usermode is not supported for axxiax86-64 BSP,
# update_pixbuf_cache postinst intercept will fail on do_rootfs.
# Overwhite pixbufcache_common function from pixbufcache.bbclass
# to skip postinst_intercept call and run only on target.
pixbufcache_common() {
if [ "x$D" == "x" ]; then
	# Update the pixbuf loaders in case they haven't been registered yet
	${libdir}/gdk-pixbuf-2.0/gdk-pixbuf-query-loaders --update-cache

	if [ -x ${bindir}/gtk-update-icon-cache ] && [ -d ${datadir}/icons ]; then
		for icondir in /usr/share/icons/*; do
			if [ -d ${icondir} ]; then
				gtk-update-icon-cache -t -q ${icondir}
			fi
		done
	fi
fi
}
