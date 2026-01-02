cmake_minimum_required(VERSION 3.10)
project(WistleDetector)

set(CMAKE_CXX_STANDARD 17)

# Find the PortAudio package
find_package(PkgConfig REQUIRED)
pkg_check_modules(PORTAUDIO REQUIRED portaudio-2.0)

add_executable(WistleDetector main.cpp)

# Link the library and include directories
target_include_directories(WistleDetector PRIVATE ${PORTAUDIO_INCLUDE_DIRS})
target_link_libraries(WistleDetector PRIVATE ${PORTAUDIO_LIBRARIES})
