BOOT_EXTRA_SIZE ?= "110"

do_install:prepend() {
	sed -i -e "s/# add 10M to provide some extra/# add ${BOOT_EXTRA_SIZE}M to provide some extra/g" ${WORKDIR}/init-install*.sh
	sed -i -e "s#boot_size=\$(( boot_size + 10 ))#boot_size=\$(( boot_size + ${BOOT_EXTRA_SIZE} ))#g" ${WORKDIR}/init-install*.sh

}
