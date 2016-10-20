#!/bin/sh
#
# $Home/.xinitrc

xset s off
xset -dpms
xsetroot -name acg
xsetroot -cursor_name left_ptr

xrandr --output eDP1 --mode 1366x768
feh --bg-scale /home/acg/usr/img/wallpapers/i_am_free.jpg
xrdb ~/.Xresources 
while :; do ~/local/bin/battery_check; sleep 120; done &
mpd
start2bwm
# exec urxvt
