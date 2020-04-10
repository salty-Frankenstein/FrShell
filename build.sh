#!/bin/bash
cd build
cmake ..
make
mv shell ../env
cd ../env
./shell
rm shell
cd ..

