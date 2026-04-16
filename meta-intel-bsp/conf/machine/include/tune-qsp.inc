# Default tune for INTEL QSP System used in simulation
DEFAULTTUNE = "core2-64"
DEFAULTTUNE:virtclass-multilib-lib32 = "core2-32"
MULTILIBS = "multilib:lib32"

SYSLINUX_OPTS = "serial 0 115200"
SERIAL_CONSOLES = "115200;ttyS0"

APPEND = "console=ttyS0"

AUTO_SYSLINUXMENU = "0"

IMAGE_FSTYPES = "hddimg wic tar.gz ext4"
