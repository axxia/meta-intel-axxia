DEFAULTTUNE ?= "cortexa15-neon"

require conf/machine/include/arm/arch-armv7a.inc

TUNEVALID[cortexa15] = "Enable Cortex-A15 specific processor optimizations"
TUNE_CCARGS += "${@bb.utils.contains("TUNE_FEATURES", "cortexa15", "-mtune=cortex-a15", "", d)}"

# Little Endian base configs
AVAILTUNES += "cortexa15 cortexa15t cortexa15-neon"
ARMPKGARCH_tune-cortexa15 ?= "cortexa15"
ARMPKGARCH_tune-cortexa15t ?= "cortexa15"
ARMPKGARCH_tune-cortexa15-neon ?= "cortexa15"

TUNE_FEATURES_tune-cortexa15 = "${TUNE_FEATURES_tune-armv7a} cortexa15 vfp neon"
TUNE_FEATURES_tune-cortexa15t = "${TUNE_FEATURES_tune-armv7at} cortexa15"
TUNE_FEATURES_tune-cortexa15-neon = "${TUNE_FEATURES_tune-armv7a-neon} cortexa15"
PACKAGE_EXTRA_ARCHS_tune-cortexa15 = "${PACKAGE_EXTRA_ARCHS_tune-armv7a} cortexa15-vfp-neon"
PACKAGE_EXTRA_ARCHS_tune-cortexa15t = "${PACKAGE_EXTRA_ARCHS_tune-armv7at} cortexa15-vfp-neon"
PACKAGE_EXTRA_ARCHS_tune-cortexa15-neon = "${PACKAGE_EXTRA_ARCHS_tune-armv7a-neon} cortexa15-vfp-neon"

# VFP Tunes
AVAILTUNES += "cortexa15hf cortexa15thf cortexa15hf-neon"
ARMPKGARCH_tune-cortexa15hf ?= "cortexa15"
ARMPKGARCH_tune-cortexa15thf ?= "cortexa15"
ARMPKGARCH_tune-cortexa15hf-neon?= "cortexa15"

TUNE_FEATURES_tune-cortexa15hf ?= "${TUNE_FEATURES_tune-armv7ahf} cortexa15"
TUNE_FEATURES_tune-cortexa15thf ?= "${TUNE_FEATURES_tune-armv7athf} cortexa15"
TUNE_FEATURES_tune-cortexa15hf-neon ?= "${TUNE_FEATURES_tune-armv7ahf-neon} cortexa15"
PACKAGE_EXTRA_ARCHS_tune-cortexa15hf = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf} cortexa15"
PACKAGE_EXTRA_ARCHS_tune-cortexa15thf = "${PACKAGE_EXTRA_ARCHS_tune-armv7athf} cortexa15"
PACKAGE_EXTRA_ARCHS_tune-cortexa15hf-neon = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf-neon} cortexa15"
