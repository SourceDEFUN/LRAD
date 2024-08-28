cmake_minimum_required(VERSION 3.12)
project(LRAD)

set(CMAKE_CXX_STANDARD 17)

ADD_LIBRARY(INeedCString
	Source/script.cpp
)
target_link_libraries(INeedCString -lcstring)

include_directories(Source)

add_executable(GPU_VRAD
        Source/basetypes.h
        Source/bsp.cpp
        Source/bsp.h
        Source/bspfile.h
        Source/bspflags.h
        Source/datamap.h
        Source/main.cpp
        Source/poly.cpp
        Source/poly.h
        Source/prettyprint.cpp
        Source/prettyprint.h
        Source/rad.cpp
        Source/rad.h
        Source/raytrace.cpp
        Source/raytrace.h
        Source/script.cpp
        Source/script.h
        Source/timer.cpp
        Source/timer.h
        Source/trace.cpp
        Source/trace.h
        Source/vector.cpp
        Source/vector.h
        Source/vmatrix.h
        Source/worldsize.h)
