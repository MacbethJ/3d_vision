cmake_minimum_required(VERSION 2.8.3)
project(pose_ekf)
add_definitions(--std=c++11 -Wno-unknown-pragmas -w)
find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)
cs_add_executable(pose_ekf src/pose_ekf_node.cpp src/pose_ekf.cpp src/conversion.cpp)
cs_install()
cs_export()