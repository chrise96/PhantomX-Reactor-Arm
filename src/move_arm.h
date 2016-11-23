#ifndef ARM_MOVEARM_H
#define ARM_MOVEARM_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include <math.h>
#include <sstream>
#include <arbotix_msgs/Relax.h>

class MoveArm {
private:
    ros::NodeHandle nodeHandle;
    ros::Publisher arm_elbow_r;
    ros::Publisher arm_elbow_l;
    ros::Publisher arm_shldr_l;
    ros::Publisher arm_shldr_r;
    ros::Publisher wrist_flex;
    ros::Publisher gripper;
    ros::Publisher arm_shldr_pan;
    ros::Publisher gsture_pub;
    ros::Subscriber sub;

public:
    MoveArm();
    ~MoveArm();

    void moveCenter();
    void movements();
};

#endif //ARM_MOVEARM_H

