cmake_minimum_required(VERSION 3.5)

project(stringsearch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stringsearch main.cpp
    BohrVertex.h BohrVertex.cpp
    StringSearch.h StringSearch.cpp
    ConsoleHandler.h ConsoleHandler.cpp)

include(GNUInstallDirs)
install(TARGETS stringsearch
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
