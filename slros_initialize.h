#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "accel_4th_order_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block accel_4th_order/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_accel_4th_order_geometry_msgs_Twist> Sub_accel_4th_order_27;

// For Block accel_4th_order/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_accel_4th_order_geometry_msgs_Twist> Pub_accel_4th_order_33;

void slros_node_init(int argc, char** argv);

#endif
