cmake_minimum_required(VERSION 2.8)

project(test6)
add_executable(${PROJECT_NAME} main.cpp
                               hasher.cpp
                               hasher.h
                               md5.cpp
                               md5.h
                               )
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
