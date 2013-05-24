#!/bin/bash

mkdir -p BUILD
cd BUILD
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$PWD ..
make
make install
