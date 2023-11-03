# IMPORTANT:
if you enable the watchdogd in your openwrt device sysupgrade will not work anymore, as it kills all "non" system
processes and thus also wht watchdogd which will cause a reset. So before doing the upgrade you need to do:
```
watchdogd disable && sysupgrade -v <sysupgrade file>
```
