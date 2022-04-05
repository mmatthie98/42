#!/bin/bash
arch=$(uname -a)
cpu=$(grep -c ^physical /proc/cpuinfo)
vcpu=$(grep -c ^processor /proc/cpuinfo)
memu=$(free -m | grep 'Mem' | awk '{print $3}')
memu1=$(free -m | grep 'Mem' | awk '{print $3*100/$2}')
memu2=$(free -m | grep 'Mem' | awk '{print $2}')
diskuse=$(df -h | grep /dev/sda1 | awk '{print ($2)}')
diskuse1=$(df -h | grep /dev/sda1 | awk '{print ($3)}')
diskuse2=$(df -h | grep /dev/sda1 | awk '{print ($5)}')
cpuload=$(top -bn1 | grep "Cpu" | awk '{print ($2)}')
lastreboot=$(who -b)
lvmuse=$(lsblk | grep lvm | awk '{if ($1) {print"yes";exit;}else{print"no";}}')
TCPconnexions=$(grep "TCP:" /proc/net/sockstat | awk '{print ($3)}')
Userlog=$(users | wc -w)
Network=$(hostname -I)
IP=$(ip l | sed -n '4p' | awk '{print($2)}')
Cmd=$(journalctl _COMM=sudo | grep 'COMMAND' | wc -l)
wall "
#Architecture: $arch
#CPU physical: $cpu
#vCPU: $vcpu
#Memory Usage: $memu / $memu2 ($memu1%)
#Disk Usage: $diskuse1 / $diskuse (taux d'utilisation : $diskuse2)
#CPU load: $cpuload
#Last boot: $lastreboot
#LVM use: $lvmuse
#Connexions TCP : $TCPconnexions ESTABLISHED
#User log: $Userlog
#Network:IP $Network ($IP)
#Cmd : $Cmd cmd"
