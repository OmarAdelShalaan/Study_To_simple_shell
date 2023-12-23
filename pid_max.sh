#!/bin/bash
max_pid=$(cat /proc/sys/kernel/pid_max)
echo "The maximum value a process ID can be is: $max_pid"
