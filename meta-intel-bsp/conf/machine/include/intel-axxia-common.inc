PREFERRED_PROVIDER_virtual/kernel ?= "linux-intel"
PREFERRED_VERSION_linux-intel ?= "5.10%"
PREFERRED_VERSION_linux-intel-rt ?= "5.10%"

require conf/machine/include/meta-intel.inc
require conf/machine/include/intel-common-pkgarch.inc

MACHINE_FEATURES += "pcbios efi"
MACHINE_FEATURES += "intel-ucode ext3"

KARCH = "x86_64"
KERNEL_IMAGETYPE = "bzImage"
KEEPUIMAGE = "no"

EFI_PROVIDER ?= "grub-efi"

IMAGE_FSTYPES += " ext2"
IMAGE_FSTYPES += " tar.gz"
IMAGE_FSTYPES += " iso"
NOISO = "0"

IMAGE_FSTYPES += "wic"
WKS_FILE = "${@bb.utils.contains_any("EFI_PROVIDER", "systemd-boot", \
	   "axxia-systemd-bootdisk-microcode.wks", \
	   "axxia-grub-bootdisk-microcode.wks", d)}"
WKS_FILE_DEPENDS_append = " intel-microcode"

# QEMU usermode fails with invalid instruction error
MACHINE_FEATURES_BACKFILL_CONSIDERED_append = " qemu-usermode"
# Disable 'update_gio_module_cache 'and 'update_font_cache' postinstall
# intercept hooks because of missing qemu usermode support
GIO_MODULE_PACKAGES_forcevariable = ""
FONT_PACKAGES_forcevariable = ""