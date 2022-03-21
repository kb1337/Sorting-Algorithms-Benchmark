#!/bin/sh

# Build program and run

set -e
# -e Exit immediately if a command exits with a non-zero status

CC=cc
CFLAGS="-Wall -Wextra"
INCLUDE="sorting_algorithms/*.c"
INCLUDE="$INCLUDE array_generator/int_array_generator.c"

$CC $CFLAGS -o benchmark "benchmark.c" $INCLUDE

./benchmark
