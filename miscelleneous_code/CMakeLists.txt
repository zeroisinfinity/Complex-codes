cmake_minimum_required(VERSION 3.31)
project(GATE_C_hobby)

set(CMAKE_CXX_STANDARD 20)

add_executable(GATE_C_hobby main.cpp
        color_blank_fill_ineff.cpp
        color_blank_fill_eff.cpp
        keeperofthecodes.cpp
        color_blank_fill_nlogn.cpp
        entry.cpp
        color_blank_fill_eff.h
        color_blank_fill_ineff.h
        keeperofthecodes.h
        entry.h
        color_blank_fill_nlogn.h
        color_blank_fill_push.cpp
        color_blank_fill_push.h
        display.cpp
        display.h
        maximum.cpp
        maximum_logn.cpp
        maximum_logn.h
        maximum.h
        maxcompact.cpp
        bubblesort_itr.h
        rec_bubblesort.h
        attach.cpp
        display_solptr.cpp
        attach.h
        display_solptr.h
        area51_gen.c
)
