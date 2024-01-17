# study-arm-assembly

Study of Arm assembly language

## Environment

- qemu-arm version 4.2.1
- QEMU emulator version 4.2.1
- gcc-arm-linux-gnueabi 9.4.0/10.5.0
- Target architecture: Armv8-A (Cortex-A family)

### Docker container

Docker container: `study-arm-assembly` with qemu environment can run by `run_docker.sh`.

- A base Docker image: `study-arm-assembly:latest` is built if it doesn't exist.
- Execute commands specified by its argument.

    ```sh
    $ ./run_docker.sh "echo hello"
    hello
    $
    ```

    When the commands doesn't be specified, launch bash with interactive mode.

    ```sh
    $ ./run_docker.sh
    ubuntu@cd5a87163a62:/workspace$
    ```

### Build and run

A specific C source file can be built with `Makefile` at the project root.

The source file specified with a Makefile variable: `SRC` is built and an executable binary (`***.elf`) is output into `build` directory.

```sh
# @Project root
$ make SRC=intro/addvalues/addvalues_inline.c
arm-linux-gnueabi-gcc -Wall -Wextra -Wpedantic -march=armv8-a -marm intro/addvalues/addvalues_inline.c -o build/addvalues_inline.elf
```

Build and execute the binary with qemu by `make run`.

```sh
# @Project root
$ make run SRC=intro/addvalues/addvalues_inline.c
arm-linux-gnueabi-gcc -Wall -Wextra -Wpedantic -march=armv8-a -marm intro/addvalues/addvalues_inline.c -o build/addvalues_inline.elf
addvalues = 3
```

## Reference

- [「ARMで学ぶ アセンブリ言語入門」](https://www.c-r.com/book/detail/927) (original sources)
- [Assembly Programming on ARM Linux](https://www.mztn.org/slasm/arm00.html)

## License

Original source codes are licensed under the Apache License, version 2.0.

In this repository, following changes are adopted to the source codes from the original:

- Change coding style
- Change file name
- Add comments
