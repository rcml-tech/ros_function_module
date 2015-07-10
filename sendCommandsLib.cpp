#include <ros/ros.h>

#include "rosHeaders.h"
#include <string>

// GLOBAL VARIABLES
ros::Rate *ploop_rate ;
ros::NodeHandle *pNode;
//

void initNode()
{
	// proxy args for ros::init()
	int proxy_argc=1;
	char* proxy_argv[] = {"proxy"};
	/////////////////////////////
	if (!ros::isInitialized()){
		ros::init(proxy_argc, proxy_argv, "rcmlFunctionsNode");
	}
	ros::NodeHandle *n = new ros::NodeHandle;
	ros::Rate *loop_rate = new ros::Rate(2);
	pNode = n;
	ploop_rate = loop_rate;
};

void clearNode()
{
	delete pNode;
	delete ploop_rate;
};

void sendHeader(std::string topic, std::string header, int seq, int sec, int nsec)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Header>(topic, 1000);
	std_msgs::Header Message;
	ros::Time time;
	time.sec = sec;
	time.nsec = nsec;

	Message.frame_id = header;
	Message.seq = seq;
	Message.stamp = time;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendMultiArrayDimension(std::string topic, std::string label, int size, int stride)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::MultiArrayDimension>(topic, 1000);
	std_msgs::MultiArrayDimension Message;
	
	Message.label = label;
	Message.size = size;
	Message.stride = stride;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendBool(std::string topic, bool data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Bool>(topic, 1000);
	std_msgs::Bool Message;
	
	Message.data = data;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendByte(std::string topic, unsigned char data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Byte>(topic, 1000);
	std_msgs::Byte Message;
	
	Message.data = data;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendChar(std::string topic, char data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Char>(topic, 1000);
	std_msgs::Char Message;
	
	Message.data = data;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendColorRGBA(std::string topic, double r, double g, double b, double a)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::ColorRGBA>(topic, 1000);
	std_msgs::ColorRGBA Message;
	
	Message.r = r;
	Message.g = g;
	Message.b = b;
	Message.a = a;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendFloat64(std::string topic, double data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Float64>(topic, 1000);
	std_msgs::Float64 Message;
	
	Message.data = data;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendInt64(std::string topic, long long data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Int64>(topic, 1000);
	std_msgs::Int64 Message;
	
	Message.data = data;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendString(std::string topic, std::string data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::String>(topic, 1000);
	std_msgs::String Message;
	
	Message.data = data;
	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendTime(std::string topic, int sec, int nsec)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::Time>(topic, 1000);
	std_msgs::Time Message;
	ros::Time time;
	time.sec = sec;
	time.nsec = nsec;

	Message.data = time;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendUInt64(std::string topic, unsigned long long data)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<std_msgs::UInt64>(topic, 1000);
	std_msgs::UInt64 Message;

	Message.data = data;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}
// Geometry_msgs

void sendVector3(std::string topic, double x, double y, double z)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Vector3>(topic, 1000);
	geometry_msgs::Vector3 Message;
	
	Message.x = x;
	Message.y = y;
	Message.z = z;
	
	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}
                 
void sendAccel(std::string topic, double lx, double ly, double lz, double ax, double ay, double az)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Accel>(topic, 1000);
	geometry_msgs::Accel Message;
	
	Message.linear.x = lx;
	Message.linear.y = ly;
	Message.linear.z = lz;
	Message.angular.x = ax;
	Message.angular.y = ay;
	Message.angular.z = az;
	
	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendPoint(std::string topic, double x, double y, double z)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Point>(topic, 1000);
	geometry_msgs::Point Message;
	
	Message.x = x;
	Message.y = y;
	Message.z = z;
	
	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendPose(std::string topic, double px, double py, double pz, double ox, double oy, double oz, double ow)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Pose>(topic, 1000);
	geometry_msgs::Pose Message;
	
	Message.position.x = px;
	Message.position.y = py;
	Message.position.z = pz;
	Message.orientation.x = ox;
	Message.orientation.y = oy;
	Message.orientation.z = oz;
	Message.orientation.w = ow;


	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendPose2D(std::string topic, double x, double y, double theta)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Pose2D>(topic, 1000);
	geometry_msgs::Pose2D Message;
	
	Message.x = x;
	Message.y = y;
	Message.theta = theta;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendQuaternion(std::string topic, double x, double y, double z, double w)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Quaternion>(topic, 1000);
	geometry_msgs::Quaternion Message;
	
	Message.x = x;
	Message.y = y;
	Message.z = z;
	Message.w = w;

	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendTransform(std::string topic, double tx, double ty, double tz, double rx, double ry, double rz, double rw)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Transform>(topic, 1000);
	geometry_msgs::Transform Message;
	
	Message.translation.x = tx;
	Message.translation.y = ty;
	Message.translation.z = tz;	
	Message.rotation.x = rx;
	Message.rotation.y = ry;
	Message.rotation.z = rz;
	Message.rotation.w = rw;


	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}

void sendTwist(std::string topic, double lx, double ly, double lz, double ax, double ay, double az)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Twist>(topic, 10);
	geometry_msgs::Twist Message;
	Message.linear.x = lx;
	Message.linear.y = ly;
	Message.linear.z = lz;
	Message.angular.x = ax;
	Message.angular.y = ay;
	Message.angular.z = az;
	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	ros::spinOnce();
	(*ploop_rate).sleep();

}

void sendWrench(std::string topic, double fx, double fy, double fz, double tx, double ty, double tz)
{
	ros::Publisher chatter_pub_int = (*pNode).advertise<geometry_msgs::Wrench>(topic, 1000);
	geometry_msgs::Wrench Message;
	
	Message.force.x = fx;
	Message.force.y = fy;
	Message.force.z = fz;
	Message.torque.x = tx;
	Message.torque.y = ty;
	Message.torque.z = tz;
	
	(*ploop_rate).sleep();
	ros::spinOnce();
	(*ploop_rate).sleep();
	chatter_pub_int.publish(Message);
	
	ros::spinOnce();
	(*ploop_rate).sleep();
}















