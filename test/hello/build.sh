#!/bin/bash

mkdir ../../../build_hello
cd ../../../build_hello
cmake -DCMAKE_TOOLCHAIN_FILE=../WomoLIN-Sw-MainUnit/test/hello/arm-gcc.cmake -DCMAKE_BUILD_TYPE=Debug ../WomoLIN-Sw-MainUnit/test/hello/
make
cd ../WomoLIN-Sw-MainUnit/test/hello
