cmake_minimum_required(VERSION 3.16)

project(dejkstra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dejkstra main.cpp)

include(GNUInstallDirs)
install(TARGETS dejkstra
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
