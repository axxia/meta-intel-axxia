BOOT_PART_SIZE ?= "50"

do_install:prepend() {
        sed -i -e "s/We need 20 Mb/We need ${BOOT_PART_SIZE} Mb/" ${WORKDIR}/init-install*.sh
        sed -i -e "s/boot_size=20/boot_size=${BOOT_PART_SIZE}/" ${WORKDIR}/init-install*.sh

}
