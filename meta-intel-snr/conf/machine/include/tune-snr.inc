# Settings for Intel Snowridge CPU with 64-bit extensions, MMX, SSE, SSE2,
# SSE3, SSSE3, SSE4.1 and SSE4.2 instruction set support.
#
# This tune is recommended for the new Intel Snowridge CPU and beyond.
#

DEFAULTTUNE ?= "snr-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/tune-core2.inc

# Extra tune features
TUNEVALID[snr] = "Enable snr specific processor optimizations"
CPU_MATCH = "${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', 'core2', 'tremont', d)}"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'snr', ' -march=${CPU_MATCH} -mtune=${CPU_MATCH} -mfpmath=sse -msse4.2', '', d)}"

# Extra tune selections
AVAILTUNES += "snr-32"
TUNE_FEATURES_tune-snr-32 = "${TUNE_FEATURES_tune-x86} snr"
BASE_LIB_tune-snr-32 = "lib"
TUNE_PKGARCH_tune-snr-32 = "snr-32"
PACKAGE_EXTRA_ARCHS_tune-snr-32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-32} snr-32"
QEMU_EXTRAOPTIONS_snr-32 = " -cpu ${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', 'n270', 'tremont', d)},check=false"

AVAILTUNES += "snr-64"
TUNE_FEATURES_tune-snr-64 = "${TUNE_FEATURES_tune-x86-64} snr"
BASE_LIB_tune-snr-64 = "lib64"
TUNE_PKGARCH_tune-snr-64 = "snr-64"
PACKAGE_EXTRA_ARCHS_tune-snr-64 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64} snr-64"
QEMU_EXTRAOPTIONS_snr-64 = " -cpu ${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', 'core2duo', 'tremont', d)},check=false"

AVAILTUNES += "snr-64-x32"
TUNE_FEATURES_tune-snr-64-x32 = "${TUNE_FEATURES_tune-x86-64-x32} snr"
BASE_LIB_tune-snr-64-x32 = "libx32"
TUNE_PKGARCH_tune-snr-64-x32 = "snr-64-x32"
PACKAGE_EXTRA_ARCHS_tune-snr-64-x32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64-x32} snr-64-x32"
QEMU_EXTRAOPTIONS_snr-64-x32 = " -cpu ${@bb.utils.contains('DISTRO_FEATURES', 'gcc8', 'core2duo', 'tremont', d)},check=false"
