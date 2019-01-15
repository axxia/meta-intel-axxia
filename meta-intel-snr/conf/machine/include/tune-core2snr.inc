# Settings for Intel Snowridge CPU with 64-bit extensions, MMX, SSE, SSE2,
# SSE3, SSSE3, SSE4.1 and SSE4.2 instruction set support.
#
# This tune is recommended for the new Intel Core 2 CPU, including Snowridge,
# and beyond.
#

DEFAULTTUNE ?= "core2snr-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/tune-core2.inc

# Extra tune features
TUNEVALID[core2snr] = "Enable core2snr specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'core2snr', ' -march=core2 -mtune=core2 -mfpmath=sse -msse4.2', '', d)}"

# Extra tune selections
AVAILTUNES += "core2snr-32"
TUNE_FEATURES_tune-core2snr-32 = "${TUNE_FEATURES_tune-x86} core2snr"
BASE_LIB_tune-core2snr-32 = "lib"
TUNE_PKGARCH_tune-core2snr-32 = "core2snr-32"
PACKAGE_EXTRA_ARCHS_tune-core2snr-32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-32} core2snr-32"
QEMU_EXTRAOPTIONS_core2snr-32 = " -cpu n270"

AVAILTUNES += "core2snr-64"
TUNE_FEATURES_tune-core2snr-64 = "${TUNE_FEATURES_tune-x86-64} core2snr"
BASE_LIB_tune-core2snr-64 = "lib64"
TUNE_PKGARCH_tune-core2snr-64 = "core2snr-64"
PACKAGE_EXTRA_ARCHS_tune-core2snr-64 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64} core2snr-64"
QEMU_EXTRAOPTIONS_core2snr-64 = " -cpu core2duo"

AVAILTUNES += "core2snr-64-x32"
TUNE_FEATURES_tune-core2snr-64-x32 = "${TUNE_FEATURES_tune-x86-64-x32} core2snr"
BASE_LIB_tune-core2snr-64-x32 = "libx32"
TUNE_PKGARCH_tune-core2snr-64-x32 = "core2snr-64-x32"
PACKAGE_EXTRA_ARCHS_tune-core2snr-64-x32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64-x32} core2snr-64-x32"
QEMU_EXTRAOPTIONS_core2snr-64-x32 = " -cpu core2duo"
