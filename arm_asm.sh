#!/bin/bash -eu

prefix=arm-linux-gnueabi
as=${prefix}-as
ld=${prefix}-ld

if [ $# -lt 1 ]; then
    echo "[Error] source file does not specified"
    echo "usage: arm_asm.sh SRC.S"
    exit
fi

src=$1

dname="$(dirname ${src})"
bin_dir="bin/${dname}"
obj_dir="${bin_dir}/obj"

fname="$(basename ${src})"
obj="${obj_dir}/${fname/.s/.o}"
bin="${bin_dir}/${fname/.s/}"

mkdir -p ${obj_dir}

echo "${as} -o ${obj} ${src}"
${as} -o ${obj} ${src}
echo "${ld} -o ${bin} ${obj}"
${ld} -o ${bin} ${obj}

