cmake_minimum_required(VERSION 2.8)
project(example)
aux_source_directory(. DIR_SRC)
add_executable(example ${DIR_SRC})
