#!/bin/bash
g++ main.cpp -fuse-ld=gold -fsanitize=address,undefined -fno-sanitize-recover=all -std=c++17 -O2 -Wall -Werror -Wsign-compare -g -o debug_solution
g++ main.cpp -std=c++17 -O2 -o fast_solution