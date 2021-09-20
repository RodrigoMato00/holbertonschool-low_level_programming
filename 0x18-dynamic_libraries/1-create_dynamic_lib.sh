#!/bin/bash
gcc *.c -Wall -pedantic -Werror -Wextra -pedantic -fPIC
gcc -shared -o liball.so *.o
