cmake_minimum_required(VERSION 3.0)
project(img2char)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( img2char img2char.cpp genChar.cpp )
target_link_libraries( img2char ${OpenCV_LIBS} )