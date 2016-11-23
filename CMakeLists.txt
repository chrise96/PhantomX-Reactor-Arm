cmake_minimum_required(VERSION 2.8.3)
project(arm_node)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package()

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(arm_node src/move_arm.cpp src/move_arm.h)
target_link_libraries(arm_node ${catkin_LIBRARIES})
add_dependencies(arm_node basic_node_generate_messages_cpp)
