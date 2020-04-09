cmake_minimum_required(VERSION 2.8)
project(Shell)
aux_source_directory(src SRC_LIST)
add_executable(shell ${SRC_LIST})

