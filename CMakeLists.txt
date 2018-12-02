cmake_minimum_required(VERSION 3.12)
project(TubesSTD_struktur_tak_terdata)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TubesSTD_struktur_tak_terdata
        jalan.cpp
        kota.cpp
        lain-lain.cpp
        main.cpp
        menu.cpp
        relasi.cpp
        semua_header.h
        welcome.cpp)
