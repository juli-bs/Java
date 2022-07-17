# TODO Aufgabe 1:
#  Setzt die "üblichen" CMake-Projekt-Einstellungen.
#
# ???
#

cmake_minimum_required(VERSION 3.17)
project(smallpt)

set(CMAKE_CXX_STANDARD 17)


if(MSVC)
    add_compile_options(/W4 /EHs)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_USE_MATH_DEFINES -D_ENABLE_ATOMIC_ALIGNMENT_FIX -D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:4194304")
else()
    add_compile_options(-Wall -Wextra -pedantic)
#   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,stack-size=4194304")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,4194304")
endif()

if(APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
elseif(UNIX AND "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    add_link_options(-latomic)
endif()


# TODO Aufgabe 1:
#  Fügt das Source-Verzeichnis zum Projekt hinzu.
#
# ???
#

add_subdirectory(src)
