# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(my_project)

# enable C++ 11
set (CMAKE_CXX_STANDARD 11)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
#find_package(OpenCV REQUIRED)

# if not, use manual specification of the OpenCVConfig.cmake path
# and comment previous line of automatic finding
find_package(OpenCV REQUIRED PATHS /home/emilioag/Desktop/installation/OpenCV-master/lib/cmake/opencv4 NO_DEFAULT_PATH)  

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Declare the executable target built from your sources
add_executable(my_project src/main.cpp src/FaceDetector.cpp)


# Link your application with OpenCV libraries
target_link_libraries(my_project PRIVATE ${OpenCV_LIBS})
