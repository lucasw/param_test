cmake_minimum_required(VERSION 2.8.3)
project(param_test)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  roslint
  sensor_msgs
  std_msgs
)

roslint_cpp()

catkin_package(
# INCLUDE_DIRS include
  LIBRARIES param_test
  CATKIN_DEPENDS nodelet roscpp sensor_msgs std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(param_test param_test.cpp)
target_link_libraries(param_test ${catkin_LIBRARIES})

add_executable(string_param_test string_param_test.cpp)
target_link_libraries(string_param_test ${catkin_LIBRARIES})
