PREFERRED_PROVIDER_virtual/kernel ?= "linux-intel"
PREFERRED_VERSION_linux-intel ?= "5.10%"
PREFERRED_VERSION_linux-intel-rt ?= "5.10%"

EFI_PROVIDER ?= "grub-efi"

require conf/machine/include/meta-intel.inc
require conf/machine/include/intel-common-pkgarch.inc

MACHINE_FEATURES += "pcbios efi"
MACHINE_FEATURES += "intel-ucode ext3"

KARCH = "x86_64"
KERNEL_IMAGETYPE = "bzImage"
KEEPUIMAGE = "no"

IMAGE_FSTYPES += " ext2"
IMAGE_FSTYPES += " tar.gz"
IMAGE_FSTYPES += " iso"

IMAGE_FSTYPES += "wic"
WKS_FILE = "axxia-bootdisk-microcode.wks.in"
WKS_FILE_DEPENDS_append = " intel-microcode"

# QEMU usermode fails with invalid instruction error
MACHINE_FEATURES_BACKFILL_CONSIDERED_append = " qemu-usermode"
# Disable 'update_gio_module_cache 'and 'update_font_cache' postinstall
# intercept hooks because of missing qemu usermode support
GIO_MODULE_PACKAGES_forcevariable = ""
FONT_PACKAGES_forcevariable = ""
