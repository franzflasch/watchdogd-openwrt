#!/bin/sh
/bin/ubus call system watchdog '{"magicclose": true}' 
/bin/ubus call system watchdog '{"stop": true}'
/usr/bin/watchdogd -T 120 -t 30 /dev/watchdog -f /etc/watchdogd.cfg -n
