/*
chrise96
Team 4
*/
#include "move_arm.h"

MoveArm::MoveArm() {
      this->arm_elbow_r = this->nodeHandle.advertise<std_msgs::Float64>("/elbow2/command", 5);
      this->arm_elbow_l = this->nodeHandle.advertise<std_msgs::Float64>("/elbow/command", 5);
      this->arm_shldr_l = this->nodeHandle.advertise<std_msgs::Float64>("/shoulder/command", 5);
      this->arm_shldr_r = this->nodeHandle.advertise<std_msgs::Float64>("/shoulder2/command", 5);
      this->wrist_flex = this->nodeHandle.advertise<std_msgs::Float64>("/wrist_flex/command", 5);
      this->gripper = this->nodeHandle.advertise<std_msgs::Float64>("/gripper/command", 5);
      this->arm_shldr_pan = this->nodeHandle.advertise<std_msgs::Float64>("/base/command", 5);
      //TODO
      this->gsture_pub = this->nodeHandle.advertise<std_msgs::String>("/armGesture", 5);
}

MoveArm::~MoveArm() {}

int main(int argc, char **argv) {
    ros::init(argc, argv, "move_arm");
    MoveArm moveArm;

    std::cout << "Starting to spin" << std::endl;

    ros::Rate loopRate(15);

    while (ros::ok()) {
      moveArm.moveCenter();

      ros::spinOnce();
      loopRate.sleep();
    }

    return EXIT_SUCCESS;
}

void MoveArm::moveCenter() {
  std_msgs::Float64 msg0, msg1;
  msg0.data = 0.0;
  msg1.data = 1.04;

  //Move Everything to center position, except gripper
  this->arm_elbow_r.publish(msg0);
  this->arm_elbow_l.publish(msg0);
  usleep(1000);
  this->arm_shldr_l.publish(msg0);
  this->arm_shldr_r.publish(msg0);
  usleep(1000);
  this->wrist_flex.publish(msg0);
  usleep(1000);
  this->arm_shldr_pan.publish(msg1);
}

