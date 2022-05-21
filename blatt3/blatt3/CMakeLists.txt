cmake_minimum_required(VERSION 3.17)
project(blatt3)


set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /EHs)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# TODO Aufgabe 1:
#  Vervollständigt diese und die weiteren CMakeLists-Dateien, sodass eine sinnvolle Projektstruktur entsteht.
#  Entfernt dazu die folgenden Befehle und startet die neue Struktur damit, das Unterverzeichnis `src` hinzuzufügen.

add_subdirectory(src)