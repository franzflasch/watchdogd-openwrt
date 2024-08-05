#!/bin/sh
/bin/ubus call system watchdog '{"magicclose": true}' 
/bin/ubus call system watchdog '{"stop": true}'
/usr/bin/watchdogd -T 60 -t 15 /dev/watchdog0 -f /etc/watchdogd.cfg -n
