#!/bin/bash -e

tag_name="study-arm-assembly:latest"
container_name="study-arm-assembly"

# Command to execute
# Execute bash when it doesn't be specified
cmd="${1:-/bin/bash}"

# Use interactive shell when the command doesn't be specified
opt_it=""
if [ $# -lt 1 ]; then
    opt_it="-it"
fi

# Build new image if it doen't exist
if [ "$(docker images ${tag_name} -q)" == "" ]; then
    docker build . -t ${tag_name}
fi

docker run -u $(id -u $USER):$(id -g $USER) \
    -v /etc/group:/etc/group:ro \
    -v /etc/passwd:/etc/passwd:ro \
    -v $(pwd):/workspace \
    --rm \
    --name ${container_name} \
    ${opt_it} ${tag_name} ${cmd}
