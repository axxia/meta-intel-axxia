require dt-axxia.inc

do_compile_append() {
	addr=0x00408000
	mk_fit_images "axm5601-emu" ${addr}
	mk_fit_images "axm5602-emu" ${addr}
	mk_fit_images "axm5604-sim" ${addr}
	mk_fit_images "axm5606-emu" ${addr}
	mk_fit_images "axm5608-sim" ${addr}
	mk_fit_images "axm5616-sim" ${addr}
}

do_deploy_append() {
	install_fit_images "axm5601-emu"
	install_fit_images "axm5602-emu"
	install_fit_images "axm5604-sim"
	install_fit_images "axm5606-emu"
	install_fit_images "axm5608-sim"
	install_fit_images "axm5616-sim"
}

