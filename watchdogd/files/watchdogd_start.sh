#!/bin/sh
/bin/ubus call system watchdog '{"magicclose": true}' 
/bin/ubus call system watchdog '{"stop": true}'
/usr/bin/watchdogd -T 30 -t 15 /dev/watchdog -f /etc/watchdogd.cfg -n
