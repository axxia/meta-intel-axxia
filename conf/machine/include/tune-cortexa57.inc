require conf/machine/include/arm/arch-armv8a.inc

TUNEVALID[cortexa57] = "Enable Cortex-A57 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexa57', bb.utils.contains('TUNE_FEATURES', [ 'crypto', 'aarch64' ], ' -mcpu=cortex-a57+crypto', ' -mcpu=cortex-a57', d), '', d)}"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexa57', ' -mtune=cortex-a57', '', d)}"

# AArch64 Little Endian base configs
AVAILTUNES += "cortexa57_64 cortexa57_64-crypto"
ARMPKGARCH_tune-cortexa57_64        ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_64-crypto ?= "cortexa57"
TUNE_FEATURES_tune-cortexa57_64        = "${TUNE_FEATURES_tune-aarch64}        cortexa57"
TUNE_FEATURES_tune-cortexa57_64-crypto = "${TUNE_FEATURES_tune-aarch64-crypto} cortexa57"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_64        = "${PACKAGE_EXTRA_ARCHS_tune-aarch64} cortexa57"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_64-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch64-crypto} cortexa57-crypto"
BASE_LIB_tune-cortexa57_64        = "${BASE_LIB_tune-aarch64}"
BASE_LIB_tune-cortexa57_64-crypto = "${BASE_LIB_tune-aarch64}"

# Aarch64 Big Endian base configs
AVAILTUNES += "cortexa57_64_be cortexa57_64_be-crypto"
ARMPKGARCH_tune-cortexa57_64_be        ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_64_be-crypto ?= "cortexa57"
TUNE_FEATURES_tune-cortexa57_64_be        = "${TUNE_FEATURES_tune-aarch64_be}        cortexa57"
TUNE_FEATURES_tune-cortexa57_64_be-crypto = "${TUNE_FEATURES_tune-aarch64_be-crypto} cortexa57"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_64_be        = "${PACKAGE_EXTRA_ARCHS_tune-aarch64_be} cortexa57_be"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_64_be-crypto = "${PACKAGE_EXTRA_ARCHS_tune-aarch64_be-crypto} cortexa57_be-crypto"
BASE_LIB_tune-cortexa57_64_be        = "${BASE_LIB_tune-aarch64}"
BASE_LIB_tune-cortexa57_64_be-crypto = "${BASE_LIB_tune-aarch64}"


# Aarch32 Little Endian base configs
AVAILTUNES += "cortexa57_32 cortexa57_32t cortexa57_32-crypto cortexa57_32t-crypto"
ARMPKGARCH_tune-cortexa57_32         ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_32t        ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_32-crypto  ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_32t-crypto ?= "cortexa57"
TUNE_FEATURES_tune-cortexa57_32         = "${TUNE_FEATURES_tune-aarch32}         cortexa57"
TUNE_FEATURES_tune-cortexa57_32t        = "${TUNE_FEATURES_tune-aarch32t}        cortexa57"
TUNE_FEATURES_tune-cortexa57_32-crypto  = "${TUNE_FEATURES_tune-aarch32-crypto}  cortexa57"
TUNE_FEATURES_tune-cortexa57_32t-crypto = "${TUNE_FEATURES_tune-aarch32t-crypto} cortexa57"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32         = "${PACKAGE_EXTRA_ARCHS_tune-aarch32} cortexa57hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32t        = "${PACKAGE_EXTRA_ARCHS_tune-cortexa57_32} cortexa57t2hf-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-cortexa57_32} cortexa57hf-crypto-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32t-crypto = "${PACKAGE_EXTRA_ARCHS_tune-cortexa57_32-crypto} cortexa57t2hf-crypto-neon-fp-armv8"

# AArch32 Big Endian base configs
AVAILTUNES += "cortexa57_32b cortexa57_32tb cortexa57_32b-crypto cortexa57_32tb-crypto"
ARMPKGARCH_tune-cortexa57_32b         ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_32tb        ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_32b-crypto  ?= "cortexa57"
ARMPKGARCH_tune-cortexa57_32tb-crypto ?= "cortexa57"
TUNE_FEATURES_tune-cortexa57_32b         = "${TUNE_FEATURES_tune-aarch32b}         cortexa57"
TUNE_FEATURES_tune-cortexa57_32tb        = "${TUNE_FEATURES_tune-aarch32tb}        cortexa57"
TUNE_FEATURES_tune-cortexa57_32b-crypto  = "${TUNE_FEATURES_tune-aarch32b-crypto}  cortexa57"
TUNE_FEATURES_tune-cortexa57_32tb-crypto = "${TUNE_FEATURES_tune-aarch32tb-crypto} cortexa57"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32b         = "${PACKAGE_EXTRA_ARCHS_tune-aarch32b} cortexa57hfb-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32tb        = "${PACKAGE_EXTRA_ARCHS_tune-cortexa57_32b} cortexa57t2hfb-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32b-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-cortexa57_32b} cortexa57hfb-crypto-neon-fp-armv8"
PACKAGE_EXTRA_ARCHS_tune-cortexa57_32tb-crypto = "${PACKAGE_EXTRA_ARCHS_tune-cortexa57_32b-crypto} cortexa57t2hfb-crypto-neon-fp-armv8"
