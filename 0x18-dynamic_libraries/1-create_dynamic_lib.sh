#!/bin/bash
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY
gcc -fPIC -c *.c
gcc -shared -o liball.so *.o
