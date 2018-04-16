# Programas exemplos de POSIX threads usando C

Este repositório contém alguns exemplos de programas escritos em C, utilizando POSIX threads.

* simples.c - programa hello world simples, passando parâmetros para threads, de maneira correta
* structs.c - programa hello world que usa structs para passar parâmetros para threads
* retorno.c - programa que exemplifica o retorno de parâmetros, da thread

## Como usar este repositório?

Baixe o repositório, através do git

```
$ git clone https://github.com/gregori/exemplos\_threads
```

Certifique-se de que você tem o compilador instalado em seu linux:

```
$ su -
# apt-get update
# apt-get install build-essential
# gcc -v
Using built-in specs.
COLLECT\_GCC=gcc
COLLECT\_LTO\_WRAPPER=/usr/lib/gcc/x86\_64-linux-gnu/5/lto-wrapper
Target: x86\_64-linux-gnu
...
Thread model: posix
gcc version ....

```

Compile todos os programas usando make:

```
$ make all
```

Os executáveis terão a extensão '.out':

```
$ ls *.out
simples.out  structs.out  retorno.out
```

