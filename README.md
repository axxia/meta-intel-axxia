meta-axxia
==========

This is the official OpenEmbedded/Yocto BSP layer for Intel’s family of
Axxia Mobile & Enterprise Communication Processors.


Supported MACHINES
==================

Boards Supported by this layer (Please refer to the associate .conf
for more information):

	* axxiaarm - Axxia 5000 ARM Mobile & Enterprise Communication 
                     Processors family (32-bit)

	* axxiaarm64 - Axxia 5000 and 6000 ARM Mobile & Enterprise 
                       Communication Processors family (64-bit)

	* axxiax86-64 - Axxia x86 Mobile & Enterprise Communication 
                        Processors family (64-bit)

NOTE: Machines are divided by architecture. By building Linux for
axxiaarm machine (e.g.), you will build binaries for all available ARM
targets.


Reference Boards
================

Amarillo – Reference board for the Axxia 5500 line of Communication
Processor devices. The 5500 device combines an ARM CPU subsystem with
up to 16 Cortex-A15 Cores along with advanced packet-processing
acceleration engines.

Victoria – Reference board for the Axxia 5600 line of Communication
Processor devices. The 5600 device combines an ARM X9 CPU subsystem
with up to 16 Cortex-A57 Cores along with advanced packet-processing
acceleration engines.

Waco – Reference board for the Axxia 6700 line of Communication
Processor devices. The 6700 device combines an ARM XLF (lionfish) CPU
subsystem with up to 32 Cortex-A53 Cores along with advanced
packet-processing acceleration engines.

Snowridge - based on x86_64 architecture - hardware is not available
yet, just the simulator.


Sources
=======

In most cases, the public repositories can be used (poky,
meta-openembedded, etc.). In the meta-axxia case, however, there are
options. Here's what is available and what each provides.

The Intel github.com repositories have the latest. To access the
private repository, request permission from Intel. Note that the
private repository is used for development and is not supported.

git clone https://github.com/axxia/meta-axxia_private.git meta-axxia

The public Intel repository contains changes that have been submitted
to Yocto, but may not have been accepted yet.

git clone https://github.com/axxia/meta-axxia.git

For changes accepted by the Yocto project, use the following.

git clone git://git.yoctoproject.org/meta-axxia

In all cases, use the 'morty' branch. The commit used as HEAD for a
particular release will be listed in the release notes.


Dependencies
============

This layer depends on:
Poky
URI: git://git.yoctoproject.org/poky.git
branch: morty
revision: HEAD

OpenEmbedded
URI: https://github.com/openembedded/meta-openembedded.git
branch: morty
revision: HEAD

Yocto Virtualization Layer
URI: git://git.yoctoproject.org/meta-virtualization
branch: morty
revision: HEAD

Intel Meta Layer
URI: git://git.yoctoproject.org/meta-intel
branch: morty
revision: HEAD


Building the meta-axxia BSP layer
=================================

To begin using the Yocto Project build tools, you must first setup your work
environment and verify that that you have the required host packages installed
on the system you will be using for builds. 

Check the YOCTO Reference Manual for the system you are using and verify you
have the minimum required packages installed. 
http://www.yoctoproject.org/docs/current/ref-manual/ref-manual.html

NOTE: You may also require packages: u-boot-tools (mkimage) and
device-tree-compiler (dtc)

1. Create an empty build directory and verify that the partition has
   at least 50Gb of free space. Next set an environment variable, YOCTO,
   to the full path.

   $ cd $HOME
   $ df -h .  # verify output shows adequate space available
   $ mkdir yocto
   $ cd yocto
   $ export YOCTO=$HOME/yocto # should also add this to your ~/.bashrc file. 

2. Clone the Yocto Project build tools (Poky) environment.

   $ cd $YOCTO
   $ git clone git://git.yoctoproject.org/poky.git
   $ cd poky
   $ git checkout morty

3. Clone the Axxia meta layer. This provides meta data for building
   images for the Axxia specific board types.  See 'Sources' above to
   select the right meta-axxia repository, branch, and version.

   $ cd $YOCTO/poky
   $ <the git clone command chosen above>
   $ cd meta-axxia
   $ git checkout morty

4. The Open Embedded project provides many useful layers and packages
   such as networking. Download the Open Embedded Yocto Project hosted
   repository with the following.

   $ cd $YOCTO/poky
   $ git clone https://github.com/openembedded/meta-openembedded.git
   $ cd meta-openembedded
   $ git checkout morty

5. Clone Yocto Virtualization Layer which provides packages for
   virtualization such as Linux Container Support (lxc).

   $ git clone git://git.yoctoproject.org/meta-virtualization
   $ cd $YOCTO/poky
   $ cd meta-virtualization
   $ git checkout morty

6. Clone the Intel meta layer. This provides Intel hardware support 
   metadata which are inherited in axxiax86-64 BSP.

   $ cd $YOCTO/poky
   $ git clone git://git.yoctoproject.org/meta-intel
   $ cd meta-intel
   $ git checkout morty

7. Create the build directory. The name is optional and will default
   to 'build', however it helps to choose a name to match the board
   type. For example, we will use axxia.

   $ cd $YOCTO
   $ source poky/meta-axxia/axxia-env
   $ source poky/oe-init-build-env axxia

8. Edit the conf/bblayers.conf file

   $ pwd (you should be at $YOCTO/axxia)
   $ vi conf/bblayers.conf

Edit BBLAYERS variable as follows. Replace references to $YOCTO below with the
actual value you provided in step 1.

   BBLAYERS ?= " \
            $YOCTO/poky/meta \
            $YOCTO/poky/meta-yocto \
            $YOCTO/poky/meta-yocto-bsp \
            $YOCTO/poky/meta-openembedded/meta-oe \
            $YOCTO/poky/meta-openembedded/meta-python \
            $YOCTO/poky/meta-openembedded/meta-networking \
            $YOCTO/poky/meta-virtualization \
            $YOCTO/poky/meta-intel \
            $YOCTO/poky/meta-axxia \
            "

9. Edit the conf/local.conf file:

   $ vi conf/local.conf

9.1 Depending on your processor, set these two options that control
    how much parallelism BitBake should use:

  BB_NUMBER_THREADS = "12"
  PARALLEL_MAKE = "-j 12"

9.2 Select a specific machine to target the build with:

    NOTE: Machines are divided by architecture. By building Linux for
    axxiaarm machine (e.g.), you will build binaries for all available
    ARM targets.

  - Axxia 3000 PPC Mobile & Enterprise Communication Processors family
    (Galveston and Elpaso)
  MACHINE = "axxiapowerpc"

  - Axxia 5500 ARM Mobile & Enterprise Communication Processors family
    (Amarillo)
  MACHINE = "axxiaarm"

  - Axxia 5600 and 6700 ARM Mobile & Enterprise Communication Processors
    family (Victoria and Waco).
  MACHINE = "axxiaarm64"
  
  - Axxia SNR Mobile & Enterprise Communication Processors family.
  MACHINE = "axxiax86-64"

9.3 Select the root filesystem image compression type (can set
    multiple types):

    NOTE: Default types are set for each machine configuration file
    from conf/machine.

    IMAGE_FSTYPES += "ext2"
    IMAGE_FSTYPES += "tar.gz"
    IMAGE_FSTYPES += "hddimg"

9.4 Select the custom bootloader as preferred:

    PREFERRED_PROVIDER_virtual/bootloader = "u-boot-axxia"

9.5 Select the kernel to use. 
    Meta-axxia is able to build the kernel from 2 sources:

a. Yocto Project Source repositories (git.yoctoproject.org)

   for standard
   PREFERRED_PROVIDER_virtual/kernel = "linux-yocto"

   for preempt-rt
   PREFERRED_PROVIDER_virtual/kernel = "linux-yocto-rt"

   will build from Yocto repos:
   4.1: http://git.yoctoproject.org/git/linux-yocto-4.1
        standard/axxia/base or standard/preempt-rt/axxia/base branch
   4.8: http://git.yoctoproject.org/git/linux-yocto-4.8 
        standard/base or standard/preempt-rt/base branch
   4.9: http://git.yoctoproject.org/git/linux-yocto-4.9 
        standard/axxia/base or standard/preempt-rt/axxia/base branch

b. Private Axxia Github (github.com/axxia)

   for standard
   PREFERRED_PROVIDER_virtual/kernel = "linux-axxia"

   for preempt-rt
   PREFERRED_PROVIDER_virtual/kernel = "linux-axxia-rt"

   will build kernel from GitHub private repos (require authentication with
   public key):
   4.1: git@github.com:axxia/axxia_yocto_linux_4.1_private.git
        standard/axxia-dev/base or standard/preempt-rt/axxia/base branch
   4.8: git@github.com:axxia/axxia_yocto_linux_4.8_private.git
        standard/axxia-dev/base or standard/preempt-rt/axxia/base branch
   4.9: git@github.com:axxia/axxia_yocto_linux_4.9_private.git
        standard/axxia-dev/base or standard/preempt-rt/axxia/base branch

9.6 Select the kernel version:

NOTE: axxiaarm and axxiaarm64 are available with linux 4.1 and 4.9
      axxiax86_64 is available with linux 4.8 and 4.9

   for 4.1, depending on PREFERRED_PROVIDER_virtual/kernel
   PREFERRED_VERSION_<preferred-provider> = "4.1%"

   for 4.8, depending on PREFERRED_PROVIDER_virtual/kernel
   PREFERRED_VERSION_<preferred-provider> = "4.8%"

   for 4.9, depending on PREFERRED_PROVIDER_virtual/kernel
   PREFERRED_VERSION_<preferred-provider>= "4.9%"

NOTE: <preferred-provider> can be linux-yocto, linux-yocto-rt,
      linux-axxia, linux-axxia-rt. See  9.5.


9.7 Customizing the Kernel .config file

NOTE: This options are available only for linux-yocto kernel.
      When building linux-axxia, fixed defconfigs are used instead.

      When building the kernel from the Yocto repositories, the final
      .config is built using configuration fragments. Otherwise, when
      building from axxiagithub, an defconfig is used.  Besides the options
      specific to the standard and preempt-rt kernel, you are able to add
      extra kernel fragments by setting the following options:

a. Power management scheme (axxiaarm and axxiaarm64 only):
   - POWER_MANAGEMENT = "low-power" (DEFAULT)
     to keep the core low power when is shut down
   - POWER_MANAGEMENT = "full-power"
     to complete power down the core when is shut down
   - POWER_MANAGEMENT = "full-power-L2"
     to complete power down the core and L2 cache when is shut down

b. Big-endian or little-endian (axxiaarm and axxiaarm64 only):
Set the order in which a sequence of bytes are stored in computer memory.
   - BIG_ENDIAN = "no" (DEFAULT)
     Little-endian is the default settings.
   - BIG_ENDIAN = "yes"
     Kernel will be built with CONFIG_CPU_BIG_ENDIAN enabled.

c. Debug options (axxiaarm and axxiaarm64 only):
   - DBG = "no" (DEFAULT)
   - DBG = "yes"
     Will enable options for debug in the Kernel config.

d. SMP options (axxiaarm and axxiaarm64 only):
   - SMP = "yes" (DEFAULT)
   - SMP = "no"
     Will enable or disable SMP related kernel options.

e. Regression testing (axxiaarm and axxiaarm64 only):
    TESTING = "yes"

f. Chip specific options (for axxiaarm64):
    CHIPSET = "X9" -> add X9 specific kernel options
    CHIPSET = "XLF" -> add XLF specific kernel options

Note: CHIPSET variable is also used for fine tuning (see 7.9) and to choose the
proper defconfig for Github builds (see 7.7).

9.8 Choose proper fine tuning for each CHIPSET As long as specfic
    tunes are defined, user can choose the proper tune using the CHIPSET
    variable. Features and flags for each tune are defined bellow:

- for axxiaarm:
    - CHIPSET = "5500" (DEFAULT) -> default tune: cortexa15-neon
        - TUNE_FEATURES = "arm armv7ve vfp  neon"
        - CFLAGS = "arm-poky-linux-gnueabi-gcc  -march=armv7ve -mfpu=neon
                    -mfloat-abi=softfp 

    - CHIPSET = "X9" -> default tune: cortexa57_32-crypto
        - TUNE_FEATURES = "arm aarch32 neon fp-armv8 callconvention-hard 
                           crypto  cortexa57"
        - CFLAGS = "arm-poky-linux-gnueabi-gcc  -mfpu=crypto-neon-fp-armv8  
                    -mfloat-abi=hard -mcpu=cortex-a57 -mtune=cortex-a57"

    - CHIPSET = "XLF" -> default tune: cortexa53_32-crypto
        - TUNE_FEATURES = "arm aarch32 neon fp-armv8 callconvention-hard 
                           crypto  cortexa53"
        - CFLAGS = "arm-poky-linux-gnueabi-gcc  -mfpu=crypto-neon-fp-armv8 
                    -mfloat-abi=hard -mcpu=cortex-a53 -mtune=cortex-a53"

- for axxiaarm64:
    - CHIPSET = "X9" (DEFAULT) -> default tune: cortexa57_64-crypto
        - TUNE_FEATURES = "aarch64 crypto cortexa57"
        - CFLAGS = "aarch64-poky-linux-gcc  -march=armv8-a+crypto 
                    -mcpu=cortex-a57+crypto -mtune=cortex-a57"

    - CHIPSET = "XLF" -> default tune: cortexa53_64-crypto
        - TUNE_FEATURES = "aarch64 crypto cortexa53"
        - CFLAGS = "aarch64-poky-linux-gcc  -march=armv8-a+crypto 
                    -mcpu=cortex-a53+crypto -mtune=cortex-a53"

NOTE: For ARMv8, AArch64 state, other availabe tunes are for BE with 
          and without crypto (crypto enables olso floating point and advanced 
          SIMD). See conf/machine/include/arm/arch-armv8a.inc
      For ARMv8, AArch32 state, default tunes include hard float, fp-armv8 
          floating-point, thumb and neon extensions. Crypto, thumb and BE are 
          optional.

- for axxiax86-64:
    - default tune: corei7-64
    - TUNE_FEATURES = "m64 corei7"
 
NOTE: For axxiax86-64 machine, no CHIPSET variable should be set.

9.9 Building a 32-bit RootFS for ARMv8 based boards:
For ARM architecture, depending on the machine selected on step 7.2, 
specific Kernel and RootFS are built for specific boards:
    - axxiaarm: 32-bit Kernel and Rootfs for 5500 board series which have
                ARMv7 based processors (cortex-a15)
    - axxiaarm64: 64-bit Kernel and Rootfs for 5600 board series which have
                  ARMv8 based processors (cortex-a53 for XLF board or 
                  cortex-a57 for X9 board).
But ARMv8 architecture support both 32-bit and 64-bit instruction sets. 
To build a 32-bit Kernel and RootFS for ARMv8, you will need to set the
following variables in local.conf:

   MACHINE = "axxiaarm"   # for 32-bit 
   CHIPSET = "X9" of CHIPSET = "XLF" (see 7.9)  # for 5600 boards (ARMv8)

If CHIPSET is not set, it will default to 5500 (ARMv7).

NOTE: You can boot the resulting 32-bit RootFS with a 64-bit Kernel 
      resulting from an axxiaarm64 build.

9.10 Other optional settings for saving disk space and build time:
   
   DL_DIR = "/<some-shared-location>/downloads"
   SSTATE_DIR = "/<some-shared-location>/sstate-cache

9.11 Examples.

     See http://www.yoctoproject.org/docs/2.3/mega-manual/mega-manual.html
     for complete documentation on the Yocto build system.

     Here are the local.conf files used for open builds.

9.11.1 axxiaarm

MACHINE = "axxiaarm"
CHIPSET = "5500"
SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
IMAGE_FSTYPES += "ext2"
IMAGE_FSTYPES += "tar.gz"
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto"
PREFERRED_VERSION_linux-yocto = "4.9%"
DISTRO ?= "poky"
PACKAGE_CLASSES ?= "package_rpm"
EXTRA_IMAGE_FEATURES = "debug-tweaks"
USER_CLASSES ?= "buildstats image-mklibs image-prelink"
PATCHRESOLVE = "noop"
BB_DISKMON_DIRS = "\
    STOPTASKS,${TMPDIR},1G,100K \
    STOPTASKS,${DL_DIR},1G,100K \
    STOPTASKS,${SSTATE_DIR},1G,100K \
    STOPTASKS,/tmp,100M,100K \
    ABORT,${TMPDIR},100M,1K \
    ABORT,${DL_DIR},100M,1K \
    ABORT,${SSTATE_DIR},100M,1K \
    ABORT,/tmp,10M,1K"
PACKAGECONFIG_append_pn-qemu-native = " sdl"
PACKAGECONFIG_append_pn-nativesdk-qemu = " sdl"
CONF_VERSION = "1"

9.11.1 axxiaarm64

MACHINE = "axxiaarm64"
CHIPSET = "X9"
SDKIMAGE_FEATURES = "dev-pkgs dbg-pkgs staticdev-pkgs"
IMAGE_FSTYPES += "ext2"
IMAGE_FSTYPES += "tar.gz"
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto-rt"
PREFERRED_VERSION_linux-yocto-rt = "4.9%"
DISTRO ?= "poky"
PACKAGE_CLASSES ?= "package_rpm"
EXTRA_IMAGE_FEATURES = "debug-tweaks"
USER_CLASSES ?= "buildstats image-mklibs image-prelink"
PATCHRESOLVE = "noop"
BB_DISKMON_DIRS = "\
    STOPTASKS,${TMPDIR},1G,100K \
    STOPTASKS,${DL_DIR},1G,100K \
    STOPTASKS,${SSTATE_DIR},1G,100K \
    STOPTASKS,/tmp,100M,100K \
    ABORT,${TMPDIR},100M,1K \
    ABORT,${DL_DIR},100M,1K \
    ABORT,${SSTATE_DIR},100M,1K \
    ABORT,/tmp,10M,1K"
PACKAGECONFIG_append_pn-qemu-native = " sdl"
PACKAGECONFIG_append_pn-nativesdk-qemu = " sdl"
CONF_VERSION = "1"

9.11.1 axxiax86-64

MACHINE = "axxiax86-64"
PREFERRED_PROVIDER_virtual/kernel = "linux-axxia"
PREFERRED_VERSION_linux-axxia = "4.8%"
DISTRO ?= "poky"
PACKAGE_CLASSES ?= "package_rpm"
EXTRA_IMAGE_FEATURES ?= "debug-tweaks"
USER_CLASSES ?= "buildstats image-mklibs image-prelink"
PATCHRESOLVE = "noop"
BB_DISKMON_DIRS = "\
    STOPTASKS,${TMPDIR},1G,100K \
    STOPTASKS,${DL_DIR},1G,100K \
    STOPTASKS,${SSTATE_DIR},1G,100K \
    STOPTASKS,/tmp,100M,100K \
    ABORT,${TMPDIR},100M,1K \
    ABORT,${DL_DIR},100M,1K \
    ABORT,${SSTATE_DIR},100M,1K \
    ABORT,/tmp,10M,1K"
PACKAGECONFIG_append_pn-qemu-native = " sdl"
PACKAGECONFIG_append_pn-nativesdk-qemu = " sdl"
CONF_VERSION = "1"

10. Select the image type and start the build
   $ cd $YOCTO/axxia
   $ bitbake <image type>

Available root filesystem types:
   * axxia-image-small 
     A small image used in simulation, flash, or as a ram disk. Should be
     sufficient to use the RTE. 

   * axxia-image-sim
     An image used in simulation.

   * axxia-image-large
     A more complete image.

   * axxia-image-large-sdk
     Image that includes everything within axxia-image-large plus meta-toolchain, 
     development headers and libraries to form a standalone SDK.

Once complete the images for the target machine will be available in the output
directory 'tmp/deploy/images/$MACHINE'.

11. Images generated:

* <image type>-<machine name>.ext2 (rootfs in EXT2 format)
* <image type>-<machine name>.tar.gz (rootfs in tar+GZIP format)
* modules-<machine name>.tgz (modules in tar+GZIP format)
* zImage and zImage-<machine name> (Linux Kernel binary, in u-boot wrapped 
format)
NOTE: For axxiaarm64, only Image files are generated, instead of zImage.
      Use mkimage to convert them to zImage format. 
* <target name>.dtb
* FIT images, 3 types:
	* fdt.fit-<target name> (DTB in fit image format)
	* linux.fit-<target name> (Kernel binary in fit image format)
	* multi.fit-<target name> (Kernel binary + DTB in fit image format)
* <image type>-<machine name>.hddimg (rootfs in hddimg format - axxiaarmx86-64)
* <image type>-<machine name>.wic (rootfs in wic format - axxiaarmx86-64)

12. Build and install the SDK:

In step 9. above, add '-c populate_sdk' to create the SDK install self
extracting script in tmp/deploy/sdk.  Simply run the poky*.sh script.
To set up the environment to use the tools, source environment-setup*
in the install directory.

Note that to include the Linux source (to build external modules), use
'bitbake axxia-image-large-sdk -c populate_sdk'.  For other targets,
the Linux source will not be available.

After the installation completes, do the following.

12.1 libnl Links

At present, no links get created in <sysroot>/usr/lib for the expected
names of the netlink libraries.  DPDK, for example, expects
libnl-3.so, but the SDK has libnl-3.so.200 (which is a link to the
actual library, libnl-3.so.200.23.0 etc.).  Fix this as follows.

cd $SYSROOT/usr/lib
ln -s libnl-3.so.200 libnl-3.so
ln -s libnl-genl-3.so.200 libnl-genl-3.so
ln -s libnl-nf-3.so.200 libnl-nf-3.so
ln -s libnl-route-3.so.200 libnl-route-3.so

12.2 Some Updates for LTTng

cd $SYSROOT/usr/lib
sed -i "s#/usr/lib#$SYSROOT/usr/lib#" liblttng-ust.la

12.3 Optional Linux Module Tools Update

If external Linux modules need to be buildable on multiple versions of
Linux hosts, and the tools were installed on the most recent version,
external Linux modules may not build.  This is because the version of
glibc on the Linux host that the SDK install script was executed on
are expected.  To use an older version, simply do the following on the
older Linux host.

source <install directory>/environment-setup*
cd $SYSROOT/usr/src/kernel
make clean silentoldconfig scripts

12.4 Creating .craff Images for Simics

When in the simics environment, the 'craff' utility should be
available.  Use 'craff' to create .craff images from the .hddimg
images as follows.

craff -o <craff image> <Yocto .hddimg>


Guidelines for submitting patches
=================================

Please submit any patches against meta-axxia BSPs to the meta-axxia
mailing list (meta-lsi@yoctoproject.org) and cc: the maintainers.

Mailing list:
	https://lists.yoctoproject.org/listinfo/meta-lsi

When creating patches, please use something like:
	git format-patch -s --subject-prefix='meta-axxia][PATCH' origin

When sending patches, please use something like:
	git send-email --to meta-lsi@yoctoproject.org --cc <maintainers>
		      <generated patch>


Maintenance
===========

Maintainers: Daniel Dragomir <daniel.dragomir@windriver.com>
	     Lucian Creanga <lucian.creanga@windriver.com>
	     John Jacques <john.jacques@intel.com>

Please see the meta-axxia/MAINTAINERS file for more details.


License
=======

All metadata is MIT licensed unless otherwise stated. Souce code included
in tree for individual recipes is under the LICENSE stated in each recipe
(.bb file) unless otherwise stated.
