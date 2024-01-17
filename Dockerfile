FROM ubuntu:20.04

RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get upgrade -y && \
    apt-get install -y tzdata

RUN apt-get update -y && apt-get install -y \
    qemu-user-static \
    qemu-system-arm \
    gcc-arm-linux-gnueabi \
    make \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /workspace
WORKDIR /workspace
