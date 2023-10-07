#!/bin/bash -eu

if [ $# -lt 1 ]; then
    echo "[Error] target binary does not specified"
    echo "usage: arm_qemu.sh TARGET"
    exit
fi

target=$1

qemu-arm-static -L /usr/arm-linux-gnueabi ${target}

