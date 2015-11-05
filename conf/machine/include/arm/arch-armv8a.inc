DEFAULTTUNE ?= "armv8a"

TUNEVALID[armv8a] = "Enable instructions for ARMv8-a"
TUNECONFLICTS[armv8a] = "armv4 armv5 armv6 armv7 armv7a"
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "armv8a", " -march=armv8-a", "", d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains("TUNE_FEATURES", "armv8a", "armv8a:", "" ,d)}"

require conf/machine/include/arm/arch-armv7a.inc

# Little Endian base configs
AVAILTUNES += "armv8a armv8a-neon"
ARMPKGARCH_tune-armv8a ?= "armv8a"
ARMPKGARCH_tune-armv8a-neon ?= "armv8a"
TUNE_FEATURES_tune-armv8a ?= "arm armv8a vfp"
TUNE_FEATURES_tune-armv8a-neon ?= "${TUNE_FEATURES_tune-armv8a} neon"
PACKAGE_EXTRA_ARCHS_tune-armv8a = "${PACKAGE_EXTRA_ARCHS_tune-armv7a} armv8a armv8a-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv8a-neon = "${PACKAGE_EXTRA_ARCHS_tune-armv8a} armv8a-vfp-neon"
