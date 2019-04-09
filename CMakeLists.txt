cmake_minimum_required(VERSION 3.13)
project(Assessment_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assessment_2 test.cpp BinarySearchTree.cpp BinarySearchTree.h Node.h)
add_executable(PartB PartB.cpp BinarySearchTree.cpp BinarySearchTree.h Node.h)