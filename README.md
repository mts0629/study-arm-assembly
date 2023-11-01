# study-arm-assembly

Study of Arm assembly language

## Environment

- qemu-arm version 4.2.1
- gcc-arm-linux-gnueabi 9.4.0/10.5.0

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

## Reference

[「ARMで学ぶ アセンブリ言語入門」](https://www.c-r.com/book/detail/927)

## License

Original source codes are licensed under the Apache License, version 2.0.

In this repository, following changes are adopted to the source codes from the original:

- Change coding style
- Change file name
- Add comments
