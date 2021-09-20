#!/bin/bash
gcc -c -Wall -pedantic -Werror -Wextra -pedantic -fPIC *.c
gcc -shared *.c -o liball.so
