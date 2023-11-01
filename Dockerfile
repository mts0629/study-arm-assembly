FROM ubuntu:20.04

RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get upgrade -y && \
    apt-get install -y tzdata

RUN apt-get update -y && apt-get install -y \
    qemu \
    qemu-user-static \
    gcc-arm-linux-gnueabi \
    make \
    vim

RUN mkdir /workspace
VOLUME /workspace
WORKDIR /workspace
