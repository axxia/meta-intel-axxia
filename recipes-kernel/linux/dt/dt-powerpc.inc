require dt-axxia.inc

do_compile_append() {
    	addr=0x00400000
	mk_fit_images "acp25xx" ${addr}
	mk_fit_images "acp342x" ${addr}
	mk_fit_images "acp344x" ${addr}
	mk_fit_images "acp35xx" ${addr}
}

do_deploy_append() {
	install_fit_images "acp25xx"
	install_fit_images "acp342x"
	install_fit_images "acp344x"
	install_fit_images "acp35xx"
}
