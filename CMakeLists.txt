cmake_minimum_required(VERSION 3.16)
project(imt CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Drogon CONFIG REQUIRED)
find_package(GTest REQUIRED)

add_executable(imt main.cpp imt.cpp)
target_link_libraries(imt PRIVATE Drogon::Drogon)

add_subdirectory(tests)