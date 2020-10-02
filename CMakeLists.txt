cmake_minimum_required(VERSION 3.5)

project(Check_client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DOx12766512=*reinterpret_cast<unsigned*>)
add_executable(Check_client main.cpp)
#add_executable(Check_client main_obfus.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
