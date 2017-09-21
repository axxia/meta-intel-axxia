require dt-axxia.inc

do_compile_append() {
	addr=0x00080000
	mk_fit_images "axm5604-sim" ${addr}
	mk_fit_images "axm5606-emu" ${addr}
	mk_fit_images "axm5608-sim" ${addr}
	mk_fit_images "axm5616-sim" ${addr}
        mk_fit_images "axm5616-victoria" ${addr}
	mk_fit_images "axc6704-sim" ${addr}
	mk_fit_images "axc6704-emu" ${addr}
	mk_fit_images "axc6716-sim" ${addr}
	mk_fit_images "axc6712-emu" ${addr}
        mk_fit_images "axc6732-waco" ${addr}
}

do_deploy_append() {
	install_fit_images "axm5604-sim"
	install_fit_images "axm5606-emu"
	install_fit_images "axm5608-sim"
	install_fit_images "axm5616-sim"
        install_fit_images "axm5616-victoria"
	install_fit_images "axc6704-sim"
	install_fit_images "axc6704-emu"
	install_fit_images "axc6716-sim"
	install_fit_images "axc6712-emu"
        install_fit_images "axc6732-waco"
}

