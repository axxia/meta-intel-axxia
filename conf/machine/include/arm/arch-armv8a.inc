TUNEVALID[arm] = "Enable ARM instruction set"
TUNEVALID[aarch32] = "Enable instructions for 32bit state for ARMv8-a (AArch32)"
TUNEVALID[aarch64] = "Enable instructions for 64bit state for ARMv8-a (AArch64)"
TUNECONFLICTS[aarch32] = "armv4 armv5 armv6 armv7 armv7a armv7ve"

require conf/machine/include/arm/arch-arm.inc
require conf/machine/include/arm/feature-arm-neon.inc
require conf/machine/include/arm/feature-arm-vfp.inc
require conf/machine/include/arm/feature-arm-thumb.inc

TUNEVALID[crypto] = "Enable ARMv8 crypto extension."
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'aarch64', bb.utils.contains('TUNE_FEATURES', 'crypto', ' -march=armv8-a+crypto', ' -march=armv8-a', d), '', d)}"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'aarch32', bb.utils.contains_any('TUNE_FEATURES', [ 'cortexa53', 'cortexa57' ], '', ' -march=armv8-a', d), '', d)}"

TUNEVALID[fp-armv8] = "Enable ARMv8 Vector Floating Point unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'fp-armv8', ' fp-armv8', '', d)}"
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', [ 'fp-armv8', 'neon' ], ' neon-fp-armv8', '', d)}"
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', [ 'fp-armv8', 'neon', 'crypto' ], ' crypto-neon-fp-armv8', '', d)}"

MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'aarch32', 'aarch32:', '' ,d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'aarch64', 'aarch64:', '' ,d)}"


# AArch32 Little Endian base configs
AVAILTUNES += "aarch32 aarch32t aarch32-crypto aarch32t-crypto"
ARMPKGARCH_tune-aarch32         ?= "aarch32"
ARMPKGARCH_tune-aarch32t        ?= "aarch32"
ARMPKGARCH_tune-aarch32-crypto  ?= "aarch32"
ARMPKGARCH_tune-aarch32t-crypto ?= "aarch32"
TUNE_FEATURES_tune-aarch32         = "arm aarch32 neon fp-armv8 callconvention-hard"
TUNE_FEATURES_tune-aarch32t        = "${TUNE_FEATURES_tune-aarch32} thumb"
TUNE_FEATURES_tune-aarch32-crypto  = "${TUNE_FEATURES_tune-aarch32} crypto"
TUNE_FEATURES_tune-aarch32t-crypto = "${TUNE_FEATURES_tune-aarch32-crypto} thumb"
PACKAGE_EXTRA_ARCHS_tune-aarch32         = "aarch32hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-aarch32t        = "${PACKAGE_EXTRA_ARCHS_tune-aarch32} aarch32t2hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-aarch32-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-aarch32} aarch32hf-crypto-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-aarch32t-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch32-crypto} aarch32t2hf-crypto-neon-fp-armv8"

# AArch32 Big Endian base configs
AVAILTUNES += "aarch32b aarch32tb aarch32b-crypto aarch32tb-crypto"
ARMPKGARCH_tune-aarch32b         ?= "aarch32"
ARMPKGARCH_tune-aarch32tb        ?= "aarch32"
ARMPKGARCH_tune-aarch32b-crypto  ?= "aarch32"
ARMPKGARCH_tune-aarch32tb-crypto ?= "aarch32"
TUNE_FEATURES_tune-aarch32b         = "${TUNE_FEATURES_tune-aarch32}         bigendian"
TUNE_FEATURES_tune-aarch32tb        = "${TUNE_FEATURES_tune-aarch32t}        bigendian"
TUNE_FEATURES_tune-aarch32b-crypto  = "${TUNE_FEATURES_tune-aarch32-crypto}  bigendian"
TUNE_FEATURES_tune-aarch32tb-crypto = "${TUNE_FEATURES_tune-aarch32t-crypto} bigendian"
PACKAGE_EXTRA_ARCHS_tune-aarch32b         = "aarch32hfb-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-aarch32tb        = "${PACKAGE_EXTRA_ARCHS_tune-aarch32b} aarch32t2hfb-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-aarch32b-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-aarch32b} aarch32hfb-crypto-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-aarch32tb-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch32b-crypto} aarch32t2hfb-crypto-neon-fp-armv8"


# AArch64 Little Endian base configs
AVAILTUNES += "aarch64 aarch64-crypto"
ARMPKGARCH_tune-aarch64        ?= "aarch64"
ARMPKGARCH_tune-aarch64-crypto ?= "aarch64"
TUNE_FEATURES_tune-aarch64         = "aarch64"
TUNE_FEATURES_tune-aarch64-crypto  = "${TUNE_FEATURES_tune-aarch64} crypto"
PACKAGE_EXTRA_ARCHS_tune-aarch64        = "aarch64"
PACKAGE_EXTRA_ARCHS_tune-aarch64-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch64} aarch64-crypto"
BASE_LIB_tune-aarch64        = "lib64"
BASE_LIB_tune-aarch64-crypto = "${BASE_LIB_tune-aarch64}"

# AArch64 Big Endian base configs
AVAILTUNES += "aarch64_be aarch64_be-crypto"
ARMPKGARCH_tune-aarch64_be        ?= "aarch64_be"
ARMPKGARCH_tune-aarch64_be-crypto ?= "aarch64_be"
TUNE_FEATURES_tune-aarch64_be        = "${TUNE_FEATURES_tune-aarch64}        bigendian"
TUNE_FEATURES_tune-aarch64_be-crypto = "${TUNE_FEATURES_tune-aarch64-crypto} bigendian"
PACKAGE_EXTRA_ARCHS_tune-aarch64_be        = "aarch64_be"
PACKAGE_EXTRA_ARCHS_tune-aarch64_be-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch64_be} aarch64_be-crypto"
BASE_LIB_tune-aarch64_be        = "${BASE_LIB_tune-aarch64}"
BASE_LIB_tune-aarch64_be-crypto = "${BASE_LIB_tune-aarch64}"


ARMPKGSFX_ENDIAN_64 = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', '_be', '', d)}"
TUNE_ARCH_64 = "aarch64${ARMPKGSFX_ENDIAN_64}"
TUNE_PKGARCH_64 = "aarch64${ARMPKGSFX_ENDIAN_64}"
ABIEXTENSION_64 = ""
TARGET_FPU_64 = ""

# Duplicated from arch-arm.inc
TUNE_ARCH_32 = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'armeb', 'arm', d)}"
TUNE_PKGARCH_32 = "${ARMPKGARCH}${ARMPKGSFX_THUMB}${ARMPKGSFX_DSP}${ARMPKGSFX_EABI}${ARMPKGSFX_ENDIAN}${ARMPKGSFX_FPU}"
ABIEXTENSION_32 = "eabi"
TARGET_FPU_32 = "${@d.getVar('TUNE_CCARGS_MFLOAT', True) or 'soft'}"

TUNE_ARCH = "${@bb.utils.contains('TUNE_FEATURES', 'aarch64', '${TUNE_ARCH_64}', '${TUNE_ARCH_32}' ,d)}"
TUNE_PKGARCH = "${@bb.utils.contains('TUNE_FEATURES', 'aarch64', '${TUNE_PKGARCH_64}', '${TUNE_PKGARCH_32}' ,d)}"
ABIEXTENSION = "${@bb.utils.contains('TUNE_FEATURES', 'aarch64', '${ABIEXTENSION_64}', '${ABIEXTENSION_32}' ,d)}"
TARGET_FPU = "${@bb.utils.contains('TUNE_FEATURES', 'aarch64', '${TARGET_FPU_64}', '${TARGET_FPU_32}' ,d)}"
