cmake_minimum_required(VERSION 2.8.3)
project(rosfunction_module)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################
## Generate added messages and services with any dependencies listed here
  generate_messages(
    DEPENDENCIES
    std_msgs
    geometry_msgs
  )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects

catkin_package(
  CATKIN_DEPENDS 
  roscpp 
  rospy 
  std_msgs 
  geometry_msgs 
  message_runtime

)

###########
## Build ##
###########
## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  ${catkin_INCLUDE_DIRS}
)


#############
## Install ##
#############

include_directories(include ${catkin_INCLUDE_DIRS})

set(PROJECT rosfunctions_module)


set(HEADERS module.h)

set(SOURCE_EXE ros_functions_module.cpp)
set(SOURCE_LIB sendCommandsLib.cpp )

add_library( sendCommandsLib STATIC ${SOURCE_LIB}  )

add_library(ros_module SHARED src/ros_functions_module.cpp)
target_link_libraries(ros_module sendCommandsLib ${catkin_LIBRARIES})
add_dependencies(ros_module rosfunction_module_generate_messages_cpp)

