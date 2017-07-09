This modules contained here are from linux.tv's mercurial, patchset "725c07a70453 tip"

A short "HOWTO compile linux.tv's dvb-drivers for 2.6.18.5-armel":

1. You have to have the cnxt-SDK for the rbmini.
2. Get the linux.tv-mercurial: "hg clone http://linuxtv.org/hg/v4l-dvb"
/* // no longer needed...
 * 3. Prepare the linux-sources within the SDK and compile it's modules:
 *  - "cd <sdk>/SRC/target/src/linux/kernel/linux-2.6.18.5"
 *  - "cp arch/arm/linux/configs/reelclient_mtd_defconfig .config"
 *  - "make menuconfig" - activate i2c-core and firmware_class as module
 *  - compile i2c-core and firmware_class:
 *   "make O=<sdk>/SRC/target/output/objs/reelclient-mtd modules CROSS_COMPILE=/opt/cnxt/bin/arm-linux-uclibcgnueabi-"
*/
4. Configure the dvb-drivers:
   - copy the v4l-config included in this directory to <v4l-prefix>/v4l-dvb/v4l/.config
   (or configure yourself with:
     "cd <v4l-prefix>/v4l-dvb/v4l"
     "make menuconfig SRCDIR=<sdk>/SRC/target/src/linux/kernel/linux-2.6.18.5 CROSS_COMPILE=/opt/cnxt/bin/arm-linux-uclibcgnueabi-" in "<v4l-prefix>/v4l-dvb")

5. Change to the linux-source-dir, Compile the dvb-drivers:
   "cd <sdk>/SRC/target/src/linux/kernel/linux-2.6.18.5"
   "make -C <v4l-prefix>/v4l-dvb O=<sdk>/SRC/target/output/objs/reelclient-mtd modules CROSS_COMPILE=/opt/cnxt/bin/arm-linux-uclibcgnueabi-"
   
