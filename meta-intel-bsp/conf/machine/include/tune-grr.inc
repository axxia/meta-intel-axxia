# Settings for Intel Grand Ridge CPU with 64-bit extensions, MOVBE, MMX, 
# SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, POPCNT, AES, PREFETCHW, PCLMUL,
# RDRND, XSAVE, XSAVEC, XSAVES, XSAVEOPT, FSGSBASE, PTWRITE, RDPID, SGX,
# GFNI-SSE, CLWB, MOVDIRI, MOVDIR64B, CLDEMOTE, WAITPKG, ADCX, AVX, AVX2,
# BMI, BMI2, F16C, FMA, LZCNT, PCONFIG, PKU, VAES, VPCLMULQDQ, SERIALIZE,
# RESET, KL, WIDEKL, AVX-VNNI, AVXIFMA, AVXVNNIINT8, AVXNECONVERT,
# CMPCCXADD and RAOINT instruction set support. 
#
# This tune is recommended for the new Intel Grand Ridge CPU and beyond.
#

DEFAULTTUNE ?= "grr-64"

DEFAULTTUNE:virtclass-multilib-lib32 ?= "grr-32"
MULTILIBS = "multilib:lib32"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/x86/tune-core2.inc

# Extra tune features
TUNEVALID[grr] = "Enable grr specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'grr', ' -march=tremont -mtune=tremont -mfpmath=sse -msse4.2', '', d)}"

# Extra tune selections
AVAILTUNES += "grr-32"
TUNE_FEATURES:tune-grr-32 = "${TUNE_FEATURES:tune-x86} grr"
BASE_LIB:tune-grr-32 = "lib"
TUNE_PKGARCH:tune-grr-32 = "grr-32"
PACKAGE_EXTRA_ARCHS:tune-grr-32 = "${PACKAGE_EXTRA_ARCHS:tune-core2-32} grr-32"
QEMU_EXTRAOPTIONS_grr-32 = " -cpu grandridge,check=false"

AVAILTUNES += "grr-64"
TUNE_FEATURES:tune-grr-64 = "${TUNE_FEATURES:tune-x86-64} grr"
BASE_LIB:tune-grr-64 = "lib64"
TUNE_PKGARCH:tune-grr-64 = "grr-64"
PACKAGE_EXTRA_ARCHS:tune-grr-64 = "${PACKAGE_EXTRA_ARCHS:tune-core2-64} grr-64"
QEMU_EXTRAOPTIONS_grr-64 = " -cpu grandridge,check=false"

AVAILTUNES += "grr-64-x32"
TUNE_FEATURES:tune-grr-64-x32 = "${TUNE_FEATURES:tune-x86-64-x32} grr"
BASE_LIB:tune-grr-64-x32 = "libx32"
TUNE_PKGARCH:tune-grr-64-x32 = "grr-64-x32"
PACKAGE_EXTRA_ARCHS:tune-grr-64-x32 = "${PACKAGE_EXTRA_ARCHS:tune-core2-64-x32} grr-64-x32"
QEMU_EXTRAOPTIONS_grr-64-x32 = " -cpu grandridge,check=false"
