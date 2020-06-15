#include <ros/ros.h>
#include<trajectory_msgs/JointTrajectoryPoint.h>
#include<trajectory_msgs/JointTrajectory.h>

int main(int argc, char** argv)
{
    ros::init(argc,argv,"chheckcontroller");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<trajectory_msgs::JointTrajectory>("/automi/master_controller/command",10);
    ros::Rate loopRate(10);
    while(ros::ok)
    {
        // ros::spinOnce();
        trajectory_msgs::JointTrajectory ans;
        ans.joint_names.push_back("r_knee"); 
        ans.joint_names.push_back("l_elbow");
        ans.points[0].positions.resize(2);
        ans.points[0].positions[0] = 2;
        ans.points[0].positions[1] = 5;
        ans.points[0].time_from_start.sec = 2;
        ans.header.stamp = ros::Time::now();
        pub.publish(ans);
    }
}