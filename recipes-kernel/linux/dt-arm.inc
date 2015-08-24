require dt-axxia.inc

do_compile_append() {
	addr=0x00408000
	mk_fit_images "axm5504-emu" ${addr}
	mk_fit_images "axm5504-sim-mmc" ${addr}
	mk_fit_images "axm5504-sim-virtio" ${addr}
	mk_fit_images "axm5504-sim" ${addr}
	mk_fit_images "axm5507-emu" ${addr}
	mk_fit_images "axm5508-amarillo" ${addr}
	mk_fit_images "axm5512-amarillo" ${addr}
	mk_fit_images "axm5516-amarillo" ${addr}
	mk_fit_images "axm5516-sim-mmc" ${addr}
	mk_fit_images "axm5516-sim-virtio" ${addr}
	mk_fit_images "axm5516-sim" ${addr}
}

do_deploy_append() {
	install_fit_images "axm5504-emu"
	install_fit_images "axm5504-sim"
	install_fit_images "axm5504-sim-mmc"
	install_fit_images "axm5504-sim-virtio"
	install_fit_images "axm5507-emu"
	install_fit_images "axm5508-amarillo"
	install_fit_images "axm5512-amarillo"
	install_fit_images "axm5516-amarillo"
	install_fit_images "axm5516-sim"
	install_fit_images "axm5516-sim-mmc"
	install_fit_images "axm5516-sim-virtio"
}
