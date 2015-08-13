#ifndef SENDCOMMANDSLIB_H
#define SENDCOMMANDSLIB_H

void initNode();
void clearNode();

void sendHeader(std::string topic, std::string header, int seq, int sec,
                int nsec);
void sendMultiArrayDimension(std::string topic, std::string lable, int size,
                             int stride);
void sendBool(std::string topic, bool data);
void sendByte(std::string topic, unsigned char data);
void sendChar(std::string topic, char data);
void sendColorRGBA(std::string topic, double r, double g, double b, double a);
void sendFloat64(std::string topic, double data);
void sendInt64(std::string topic, long long data);
void sendString(std::string topic, std::string data);
void sendTime(std::string topic, int sec, int nsec);
void sendUInt64(std::string topic, unsigned long long data);
// Geometry_msgs
void sendVector3(std::string topic, double x, double y, double z);
void sendAccel(std::string topic, double lx, double ly, double lz, double ax,
               double ay, double az);
void sendPoint(std::string topic, double x, double y, double z);
void sendPose(std::string topic, double px, double py, double pz, double ox,
              double oy, double oz, double ow);
void sendPose2D(std::string topic, double x, double y, double theta);
void sendQuaternion(std::string topic, double x, double y, double z, double w);
void sendTransform(std::string topic, double tx, double ty, double tz,
                   double rx, double ry, double rz, double rw);
void sendTwist(std::string topic, double lx, double ly, double lz, double ax,
               double ay, double az);
void sendWrench(std::string topic, double fx, double fy, double fz, double tx,
                double ty, double tz);

#endif  // SENDCOMMANDSLIB_H
