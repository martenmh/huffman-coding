cmake_minimum_required(VERSION 3.15)
project(huffman)

set(CMAKE_CXX_STANDARD 14)
include_directories( include)
add_executable(huffman src/main.cpp src/HuffmanList.cpp src/HuffmanTree.cpp)
target_link_libraries( huffman )



