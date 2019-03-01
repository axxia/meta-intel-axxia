KV = "4.19"

SNR_PATCHES = " \
file://SNR-0001-i2c-ismt-Add-support-for-Intel-Cedar-Fork.patch \
"

FRIO_PATCHES = " \
file://FRIO-0001-PCI-ASPM-Don-t-retrain-link.patch \
file://FRIO-0002-drivers-pci-acs-override.patch \
"

require linux-axxia.inc
