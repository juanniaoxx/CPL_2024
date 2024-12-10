#!/usr/bin/env bash
set -e

gcc $(find . -name "*.c") -std=c17 -lm -march=native -O2 -fno-strict-aliasing -Wall -DONLINE_JUDGE -fdiagnostics-color=always -o majsa

# 这是 OJ 会在 Linux 系统中执行的编译脚本，你可以在本地 Linux 系统中用该指令编译测试。