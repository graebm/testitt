cmake_minimum_required(VERSION 3.13)

project(myapp)

# find ittnotify (install it somewhere CMake will look, or set CMAKE_PREFIX_PATH)
find_library(ITTNOTIFY_LIB ittnotify REQUIRED)
find_file(ITTNOTIFY_H ittnotify.h REQUIRED)
get_filename_component(ITTNOTIFY_INCLUDE ${ITTNOTIFY_H} DIRECTORY)
message(STATUS "ITTNOTIFY_LIB: ${ITTNOTIFY_LIB}")
message(STATUS "ITTNOTIFY_H: ${ITTNOTIFY_H}")

################################################################################
# mylib
################################################################################
add_library(mylib STATIC mylib.c)

# use ittnotify
target_include_directories(mylib PUBLIC ${ITTNOTIFY_INCLUDE})
target_link_libraries(mylib PUBLIC ${ITTNOTIFY_LIB})

# ittnotify needs dl
target_link_libraries(mylib PRIVATE dl)

# use threads
find_package(Threads)
target_link_libraries(mylib PRIVATE ${CMAKE_THREAD_LIBS_INIT})

################################################################################
# myapp
################################################################################
add_executable(myapp myapp.c)

# use mylib
target_link_libraries(myapp mylib)
