#!/bin/bash -eu

if [ $# -lt 1 ]; then
    echo "[Error] tag name does not be specified"
    echo "usage: run_docker.sh TAG_NAME [CONTAINER_NAME]"
    exit
fi

tag_name=$1


container_name=study-arm-assembly

if [ $# -eq 2 ]; then
    container_name=$2
fi

docker run -u $(id -u $USER):$(id -g $USER) \
    -v /etc/group:/etc/group:ro \
    -v /etc/passwd:/etc/passwd:ro \
    -v $(pwd):/workspace \
    --rm \
    --name ${container_name} \
    -it ${tag_name} /bin/bash

