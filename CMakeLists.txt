cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)
project(cannyline)

OPTION(USE_PYBIND "Enable pybind" ON)

# debug or release
SET(CMAKE_BUILD_TYPE "Release")


# arm or x86
IF(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
    SET(PLATFORM_COMPILE_FLAGS "-mfpu=neon")
ELSE()
    SET(PLATFORM_COMPILE_FLAGS "-march=native")

    # some places of the algorithm are designed for 128 SIMD
    # so 128 SSE may slightly faster than 256 AVX, you may want this
#    SET(PLATFORM_COMPILE_FLAGS "-msse -msse2 -msse3 -msse4 -mssse3")  # SSE only
ENDIF()

# SET(PLATFORM_COMPILE_FLAGS "-DMIPP_NO_INTRINSICS")  # close SIMD
#SET(COMMON_COMPILE_FLAGS "-fopenmp -Wall -Wno-sign-compare")
#SET(CMAKE_CXX_FLAGS "${PLATFORM_COMPILE_FLAGS} ${COMMON_COMPILE_FLAGS} $ENV{CXXFLAGS}")
#SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g2 -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3")


# opencv
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /opt/ros/kinetic)
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# location module
include_directories (${INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_SOURCE_DIR}/src)

# test exe
#FILE(GLOB_RECURSE HDRS_FILES ${PROJECT_SOURCE_DIR}/src/*.h)
#FILE(GLOB_RECURSE SRCS_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
#
#ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS_FILES} ${HDRS_FILES})
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})

# pybind
if (USE_PYBIND)
    find_package(PythonLibs 3 REQUIRED)
    find_package(pybind11 REQUIRED)
    include(pybind11/Cmake/FindNumPy.cmake)
    set(SOURCE_PYBIND
        pybind11/CannyLine.cpp
        pybind11/np2mat/ndarray_converter.cpp)
    include_directories(${INCLUDE_DIRECTORIES}
            ${PYTHON_INCLUDE_DIRS}
            ${PYTHON_NUMPY_INCLUDE_DIR})
    pybind11_add_module(${PROJECT_NAME} src/MetaLine.cpp ${SOURCE_PYBIND})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
endif()