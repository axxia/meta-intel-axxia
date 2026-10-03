# Settings for Intel Palm Ridge CPU with 64-bit extensions, MOVBE, MMX, 
# SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, POPCNT, AES, PREFETCHW, PCLMUL,
# RDRND, XSAVE, XSAVEC, XSAVES, XSAVEOPT, FSGSBASE, PTWRITE, RDPID, SGX,
# GFNI-SSE, CLWB, MOVDIRI, MOVDIR64B, CLDEMOTE, WAITPKG, ADCX, AVX, AVX2,
# BMI, BMI2, F16C, FMA, LZCNT, PCONFIG, PKU, VAES, VPCLMULQDQ, SERIALIZE,
# RESET, KL, WIDEKL, AVX-VNNI, AVXIFMA, AVXVNNIINT8, AVXNECONVERT,
# CMPCCXADD and RAOINT instruction set support. 
#
# This tune is recommended for the new Intel Palm Ridge CPU and beyond.
#

DEFAULTTUNE ?= "pmr-64"

DEFAULTTUNE:virtclass-multilib-lib32 ?= "pmr-32"
MULTILIBS = "multilib:lib32"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/x86/tune-core2.inc

# Extra tune features
TUNEVALID[pmr] = "Enable pmr specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'pmr', ' -march=grandridge -mtune=grandridge -mfpmath=sse -mavx2', '', d)}"

# Extra tune selections
AVAILTUNES += "pmr-32"
TUNE_FEATURES:tune-pmr-32 = "${TUNE_FEATURES:tune-x86} pmr"
BASE_LIB:tune-pmr-32 = "lib"
TUNE_PKGARCH:tune-pmr-32 = "pmr-32"
PACKAGE_EXTRA_ARCHS:tune-pmr-32 = "${PACKAGE_EXTRA_ARCHS:tune-core2-32} pmr-32"
QEMU_EXTRAOPTIONS_pmr-32 = " -cpu Skylake-Client,check=false"

AVAILTUNES += "pmr-64"
TUNE_FEATURES:tune-pmr-64 = "${TUNE_FEATURES:tune-x86-64} pmr"
BASE_LIB:tune-pmr-64 = "lib64"
TUNE_PKGARCH:tune-pmr-64 = "pmr-64"
PACKAGE_EXTRA_ARCHS:tune-pmr-64 = "${PACKAGE_EXTRA_ARCHS:tune-core2-64} pmr-64"
QEMU_EXTRAOPTIONS_pmr-64 = " -cpu Skylake-Client,check=false"

AVAILTUNES += "pmr-64-x32"
TUNE_FEATURES:tune-pmr-64-x32 = "${TUNE_FEATURES:tune-x86-64-x32} pmr"
BASE_LIB:tune-pmr-64-x32 = "libx32"
TUNE_PKGARCH:tune-pmr-64-x32 = "pmr-64-x32"
PACKAGE_EXTRA_ARCHS:tune-pmr-64-x32 = "${PACKAGE_EXTRA_ARCHS:tune-core2-64-x32} pmr-64-x32"
QEMU_EXTRAOPTIONS_pmr-64-x32 = " -cpu Skylake-Client,check=false"
