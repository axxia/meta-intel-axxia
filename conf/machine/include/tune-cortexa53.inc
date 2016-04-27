require conf/machine/include/arm/arch-armv8a.inc

TUNEVALID[cortexa53] = "Enable Cortex-A53 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexa53', bb.utils.contains('TUNE_FEATURES', [ 'crypto', 'aarch64' ], ' -mcpu=cortex-a53+crypto', ' -mcpu=cortex-a53', d), '', d)}"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexa53', ' -mtune=cortex-a53', '', d)}"

# AArch64 Little Endian base configs
AVAILTUNES += "cortexa53_64 cortexa53_64-crypto"
ARMPKGARCH_tune-cortexa53_64        ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_64-crypto ?= "cortexa53"
TUNE_FEATURES_tune-cortexa53_64        = "${TUNE_FEATURES_tune-aarch64}        cortexa53"
TUNE_FEATURES_tune-cortexa53_64-crypto = "${TUNE_FEATURES_tune-aarch64-crypto} cortexa53"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_64        = "${PACKAGE_EXTRA_ARCHS_tune-aarch64} cortexa53"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_64-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch64-crypto} cortexa53-crypto"
BASE_LIB_tune-cortexa53_64        = "${BASE_LIB_tune-aarch64}"
BASE_LIB_tune-cortexa53_64-crypto = "${BASE_LIB_tune-aarch64}"

# Aarch64 Big Endian base configs
AVAILTUNES += "cortexa53_64_be cortexa53_64_be-crypto"
ARMPKGARCH_tune-cortexa53_64_be        ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_64_be-crypto ?= "cortexa53"
TUNE_FEATURES_tune-cortexa53_64_be        = "${TUNE_FEATURES_tune-aarch64_be}        cortexa53"
TUNE_FEATURES_tune-cortexa53_64_be-crypto = "${TUNE_FEATURES_tune-aarch64_be-crypto} cortexa53"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_64_be        = "${PACKAGE_EXTRA_ARCHS_tune-aarch64_be} cortexa53_be"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_64_be-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch64_be-crypto} cortexa53_be-crypto"
BASE_LIB_tune-cortexa53_64_be        = "${BASE_LIB_tune-aarch64}"
BASE_LIB_tune-cortexa53_64_be-crypto = "${BASE_LIB_tune-aarch64}"


# Aarch32 Little Endian base configs
AVAILTUNES += "cortexa53_32 cortexa53_32t cortexa53_32-crypto cortexa53_32t-crypto"
ARMPKGARCH_tune-cortexa53_32         ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_32t        ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_32-crypto  ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_32t-crypto ?= "cortexa53"
TUNE_FEATURES_tune-cortexa53_32         = "${TUNE_FEATURES_tune-aarch32}         cortexa53"
TUNE_FEATURES_tune-cortexa53_32t        = "${TUNE_FEATURES_tune-aarch32t}        cortexa53"
TUNE_FEATURES_tune-cortexa53_32-crypto  = "${TUNE_FEATURES_tune-aarch32-crypto}  cortexa53"
TUNE_FEATURES_tune-cortexa53_32t-crypto = "${TUNE_FEATURES_tune-aarch32t-crypto} cortexa53"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32         = "${PACKAGE_EXTRA_ARCHS_tune-aarch32} cortexa53hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32t        = "${PACKAGE_EXTRA_ARCHS_tune-cortexa53_32} cortexa53t2hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-cortexa53_32} cortexa53hf-crypto-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32t-crypto = "${PACKAGE_EXTRA_ARCHS_tune-cortexa53_32-crypto} cortexa53t2hf-crypto-neon-fp-armv8"

# AArch32 Big Endian base configs
AVAILTUNES += "cortexa53_32b cortexa53_32tb cortexa53_32b-crypto cortexa53_32tb-crypto"
ARMPKGARCH_tune-cortexa53_32b         ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_32tb        ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_32b-crypto  ?= "cortexa53"
ARMPKGARCH_tune-cortexa53_32tb-crypto ?= "cortexa53"
TUNE_FEATURES_tune-cortexa53_32b         = "${TUNE_FEATURES_tune-aarch32b}         cortexa53"
TUNE_FEATURES_tune-cortexa53_32tb        = "${TUNE_FEATURES_tune-aarch32tb}        cortexa53"
TUNE_FEATURES_tune-cortexa53_32b-crypto  = "${TUNE_FEATURES_tune-aarch32b-crypto}  cortexa53"
TUNE_FEATURES_tune-cortexa53_32tb-crypto = "${TUNE_FEATURES_tune-aarch32tb-crypto} cortexa53"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32b         = "${PACKAGE_EXTRA_ARCHS_tune-aarch32b} cortexa53hfb-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32tb        = "${PACKAGE_EXTRA_ARCHS_tune-cortexa53_32b} cortexa53t2hfb-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32b-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-cortexa53_32b} cortexa53hfb-crypto-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa53_32tb-crypto = "${PACKAGE_EXTRA_ARCHS_tune-cortexa53_32b-crypto} cortexa53t2hfb-crypto-neon-fp-armv8"
