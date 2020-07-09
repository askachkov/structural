cmake_minimum_required(VERSION 3.0)
project(struct_app)
set(SOURCE main.cpp factory.cpp node.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})