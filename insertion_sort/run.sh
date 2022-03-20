#!/bin/sh

# Build program and run

set -e
# -e Exit immediately if a command exits with a non-zero status

CC=cc
CFLAGS="-Wall -Wextra"

$CC $CFLAGS -o insertion_sort "insertion_sort.c" "../array_generator/int_array_generator.c"

./insertion_sort
