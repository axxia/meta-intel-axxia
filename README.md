meta-intel-axxia
================

This is the official OpenEmbedded/Yocto BSP layer for Intel’s family of
Axxia x86-64 Mobile & Enterprise Communication Processors.


Supported MACHINES
==================

Boards Supported by this layer (Please refer to the associate .conf
for more information):

	* axxiax86-64 - Axxia x86 Mobile & Enterprise Communication 
                        Processors family (64-bit)

Reference Boards
================

Snowridge - based on x86_64 architecture - hardware is not available
yet, just the simulator.


Sources
=======

In most cases, the public repositories can be used (poky,
meta-openembedded, etc.). In the meta-intel-axxia case, however, there
are options. Here's what is available and what each provides.

The Intel github.com repositories have the latest. To access the
private repository, request permission from Intel. Note that the
private repository is used for development and is not supported.

git clone https://github.com/axxia/meta-intel-axxia_private.git meta-intel-axxia

The public Intel repository contains changes that have been submitted
to Yocto, but may not have been accepted yet.

git clone https://github.com/axxia/meta-intel-axxia.git

In all cases, use the 'rocko' branch. The commit used as HEAD for a
particular release will be listed in the release notes.


Dependencies
============

This layer depends on:
Poky
URI: git://git.yoctoproject.org/poky.git
branch: rocko
revision: HEAD

OpenEmbedded
URI: https://github.com/openembedded/meta-openembedded.git
branch: rocko
revision: HEAD

Yocto Virtualization Layer
URI: git://git.yoctoproject.org/meta-virtualization
branch: rocko
revision: HEAD

Intel Meta Layer
URI: git://git.yoctoproject.org/meta-intel
branch: rocko
revision: HEAD


Building the meta-intel-axxia BSP layer
=======================================

To begin using the Yocto Project build tools, you must first setup your work
environment and verify that that you have the required host packages installed
on the system you will be using for builds. 

Check the YOCTO Reference Manual for the system you are using and verify you
have the minimum required packages installed. 
http://www.yoctoproject.org/docs/current/ref-manual/ref-manual.html

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
   $ git checkout rocko

3. Clone the Axxia meta layer. This provides meta data for building
   images for the Axxia specific board types.  See 'Sources' above to
   select the right meta-intel-axxia repository, branch, and version.

   $ cd $YOCTO/poky
   $ <the git clone command chosen above>
   $ cd meta-intel-axxia
   $ git checkout rocko

4. The Open Embedded project provides many useful layers and packages
   such as networking. Download the Open Embedded Yocto Project hosted
   repository with the following.

   $ cd $YOCTO/poky
   $ git clone https://github.com/openembedded/meta-openembedded.git
   $ cd meta-openembedded
   $ git checkout rocko

5. Clone Yocto Virtualization Layer which provides packages for
   virtualization such as Linux Container Support (lxc).

   $ git clone git://git.yoctoproject.org/meta-virtualization
   $ cd $YOCTO/poky
   $ cd meta-virtualization
   $ git checkout rocko

6. Clone the Intel meta layer. This provides Intel hardware support 
   metadata which are inherited in axxiax86-64 BSP.

   $ cd $YOCTO/poky
   $ git clone git://git.yoctoproject.org/meta-intel
   $ cd meta-intel
   $ git checkout rocko

7. Create the build directory. The name is optional and will default
   to 'build', however it helps to choose a name to match the board
   type. For example, we will use axxia.

   $ cd $YOCTO
   $ source poky/meta-intel-axxia/axxia-env
   $ source poky/oe-init-build-env axxia

8. Edit the conf/bblayers.conf file

   $ pwd (you should be at $YOCTO/axxia)
   $ vi conf/bblayers.conf

Edit BBLAYERS variable as follows. Replace references to $YOCTO below with the
actual value you provided in step 1.

   BBLAYERS ?= " \
            $YOCTO/poky/meta \
            $YOCTO/poky/meta-poky \
            $YOCTO/poky/meta-openembedded/meta-oe \
            $YOCTO/poky/meta-openembedded/meta-python \
            $YOCTO/poky/meta-openembedded/meta-networking \
            $YOCTO/poky/meta-virtualization \
            $YOCTO/poky/meta-intel \
            $YOCTO/poky/meta-intel-axxia \
            $YOCTO/poky/meta-intel-axxia/meta-intel-snr \
            "

9. Edit the conf/local.conf file:

   $ vi conf/local.conf

9.1 Set distribution configuration to have all Axxia specific features.

    DISTRO = "intel-axxia"

9.2 Depending on your processor, set these two options that control
    how much parallelism BitBake should use:

    BB_NUMBER_THREADS = "12"
    PARALLEL_MAKE = "-j 12"

9.3 Select a specific machine to target the build with:

    - Axxia SNR Mobile & Enterprise Communication Processors family.
    MACHINE = "axxiax86-64"

9.4 Select the kernel to use.
    Meta-intel-axxia is able to build the kernel from 2 sources:

a. Yocto Project Source repositories (git.yoctoproject.org)

   for standard
   PREFERRED_PROVIDER_virtual/kernel = "linux-yocto"

   for preempt-rt
   PREFERRED_PROVIDER_virtual/kernel = "linux-yocto-rt"

   will build from Yocto repos:
   4.9: http://git.yoctoproject.org/git/linux-yocto-4.9
        standard/axxia/base or standard/preempt-rt/axxia/base branch

   will build from Yocto repos:
   4.12: http://git.yoctoproject.org/git/linux-yocto-4.12
        standard/axxia/base or standard/preempt-rt/axxia/base branch

b. Private Axxia Github (github.com/axxia)

   for standard
   PREFERRED_PROVIDER_virtual/kernel = "linux-axxia"

   for preempt-rt
   PREFERRED_PROVIDER_virtual/kernel = "linux-axxia-rt"

   will build kernel from GitHub private repos (require authentication with
   public key):
   4.9: git@github.com:axxia/axxia_yocto_linux_4.9_private.git
        standard/axxia-dev/base or standard/preempt-rt/axxia/base branch

   4.9: git@github.com:axxia/axxia_yocto_linux_4.12_private.git
        standard/axxia-dev/base or standard/preempt-rt/axxia/base branch

9.5 Select the kernel version:

   for 4.9, depending on PREFERRED_PROVIDER_virtual/kernel
   PREFERRED_VERSION_<preferred-provider>= "4.9%"

   for 4.12, depending on PREFERRED_PROVIDER_virtual/kernel
   PREFERRED_VERSION_<preferred-provider>= "4.12%"

NOTE: <preferred-provider> can be linux-yocto, linux-yocto-rt,
      linux-axxia, linux-axxia-rt. See  9.5.


9.6 Choose the System where the image will run between simulation and 
    emulation:

    for Simics Simulation System (default):
    RUNTARGET = "simics"

    for Frio FPGA Emulation System:
    RUNTARGET = "frio"


9.7 Other optional settings for saving disk space and build time:
   
   DL_DIR = "/<some-shared-location>/downloads"
   SSTATE_DIR = "/<some-shared-location>/sstate-cache

9.8 Examples.

     See http://www.yoctoproject.org/docs/2.3/mega-manual/mega-manual.html
     for complete documentation on the Yocto build system.

     Here are the local.conf files used for open builds:

MACHINE = "axxiax86-64"
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto"
PREFERRED_VERSION_linux-yocto = "4.12%"
DISTRO = "intel-axxia"
RUNTARGET = "simics"
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
     A small image used in simulation, flash, or as a ram disk. Should
     be sufficient to use the RTE. 

   * axxia-image-sim
     An image used in simulation.

   * axxia-image-large
     A more complete image.

   * axxia-image-large-sdk
     Image that includes everything within axxia-image-large plus 
     meta-toolchain, development headers and libraries to form a 
     standalone SDK.

Once complete the images for the target machine will be available in 
the output directory 'tmp/deploy/images/$MACHINE'.

11. Images generated:

* <image type>-<machine name>.ext2 (rootfs in EXT2 format)
* <image type>-<machine name>.ext4 (rootfs in EXT4 format)
* <image type>-<machine name>.tar.gz (rootfs in tar+GZIP format)
* <image type>-<machine name>.hddimg (rootfs in hddimg format)
* <image type>-<machine name>.wic (rootfs in wic format)
* modules-<machine name>.tgz (modules in tar+GZIP format)
* bzImage and bzImage-<machine name> (Linux Kernel binary)

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
sed -i "s|/usr/lib|$SYSROOT/usr/lib|" liblttng-ust.la

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

Please submit any patches against meta-intel-axxia BSPs to the 
meta-intel-axxia mailing list (meta-lsi@yoctoproject.org) and 
cc: the maintainers.

Mailing list:
    https://lists.yoctoproject.org/listinfo/meta-lsi

When creating patches, please use something like:
    git format-patch -s --subject-prefix='meta-intel-axxia][PATCH' origin

When sending patches, please use something like:
    git send-email --to meta-lsi@yoctoproject.org --cc <maintainers>
		      <generated patch>


Maintenance
===========

Maintainers: Daniel Dragomir <daniel.dragomir@windriver.com>
	     John Jacques <john.jacques@intel.com>

Please see the meta-intel-axxia/MAINTAINERS file for more details.


License
=======

All metadata (except simicsfs module) is MIT licensed unless otherwise stated.
Souce code included in tree for individual recipes is under the LICENSE stated
in each recipe (.bb file) unless otherwise stated.

The simicsfs external module is licensed under the GPLv2 (licence file included
meta-intel-axxia layer).
