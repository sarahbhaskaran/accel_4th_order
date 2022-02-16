#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "accel_4th_order";

// For Block accel_4th_order/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_accel_4th_order_geometry_msgs_Twist> Sub_accel_4th_order_27;

// For Block accel_4th_order/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_accel_4th_order_geometry_msgs_Twist> Pub_accel_4th_order_33;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

