# This is an OpenWRT package for watchdogd (https://troglobit.com/projects/watchdogd/)
It includes also dependencies and procd init files. It disables the procd watchdog, so 
please be aware of the following important info:

# IMPORTANT:
if you enable the watchdogd in your openwrt device, sysupgrade will not work anymore, as it kills all "non" system
processes and thus also watchdogd which will cause a reset!! This could potentially brick your device!!!

So a sysupgrade should be done like this:
```
watchdogd disable && sysupgrade -v <sysupgrade file>
```

# How to build
1. Add it into your OpenWrt build folder. I always create a new folder in packages (e.g. packages/mypackages)
2. Clone this repository to packages/mypackages
3. ```make menuconfig``` -> select watchdogd
4. build OpenWrt.

# build-modify-build sources
1. clone source tree to some location
```git clone https://github.com/franzflasch/watchdogd.git```
2. if needed exec "autogen.sh" inside source tree for autotools based projects
3. prepare build
```make package/mypackages/watchdogd-openwrt/watchdogd/prepare USE_SOURCE_DIR=<source-tree-location> V=s```
4. build
```make package/mypackages/watchdogd-openwrt/watchdogd/compile V=s```

# How to use
https://troglobit.com/projects/watchdogd/
