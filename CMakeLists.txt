cmake_minimum_required(VERSION 3.25)
project(FaceDetection VERSION 1.0)

add_executable(FaceDetection FaceDetection.cpp)

find_package(Logger REQUIRED)
find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(FaceDetection PUBLIC DebugTools::Logger wiringPi pthread ${OpenCV_LIBS})
#target_include_directories(FaceDetection PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/MyLibrary")
#include_directories(/usr/local/include/opencv4)

