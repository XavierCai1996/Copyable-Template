#!/bin/bash

#build
cmake .
make

#clear
rm ./cmake_install.cmake
rm -r ./CMakeFiles
rm ./Makefile
rm ./CMakeCache.txt

#run
echo
echo "***** Example Start *****"
./example
echo "***** Example  End  *****"
