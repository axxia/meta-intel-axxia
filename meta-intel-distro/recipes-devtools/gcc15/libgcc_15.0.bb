require recipes-devtools/gcc15/gcc-${PV}.inc
require libgcc.inc

LDFLAGS += "-fuse-ld=bfd"

# Building with thumb enabled on armv6t fails
ARM_INSTRUCTION_SET:armv6 = "arm"
