cmake_minimum_required(VERSION 2.8)

project (Interlacing)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
find_package( OpenCV REQUIRED )

add_executable (Interlacing main.cpp DualVideoInput.cpp)
target_link_libraries( Interlacing ${OpenCV_LIBS} )

project (GenerateTests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package( OpenCV REQUIRED )

add_executable (GenerateTests GenerateTests.cpp)
target_link_libraries( GenerateTests ${OpenCV_LIBS} )
