/*
 *  YDLIDAR SYSTEM
 *  YDLIDAR ROS Node Client 
 *
 *  Copyright 2015 - 2018 EAI TEAM
 *  http://www.ydlidar.com
 * 
 */
 
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <stdio.h>
#define RAD2DEG(x) ((x)*180./M_PI)
 
void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    FILE *fp
    int count = scan->scan_time / scan->time_increment;
    printf("[YDLIDAR INFO]: I heard a laser scan %s[%d]:\n", scan->header.frame_id.c_str(), count);
    printf("[YDLIDAR INFO]: angle_range : [%f, %f]\n", RAD2DEG(scan->angle_min), RAD2DEG(scan->angle_max));
    int obstacle = 0; // 0(no obstacle or back): straigt, 1(front): back, 2(left): turn right, 3(right): turn left
    
	for(int i = 0; i < count; i++) {
        float degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
 	float distance = scan->ranges[i];

if(degree > -30 && degree <30) //check front
        {
         
        if (distance < Boundary_Distance && distance >0)
                { printf("distance : %f\n", distance); obstacle=1; break;}
        else
            continue;
 
        }
    //check right
    else if(degree>30 && degree<135)
    {
        if (distance < Boundary_Distance && distance >0)
                        { printf("degree :%.2f distance : %.2f\n",degree, distance); obstacle=3; break;}
                else
                        continue;
     
    }   
 
     
//check back
    else if(degree>135 && degree<-135)
        {
            if (distance < Boundary_Distance && distance >0)
                        { printf("distance : %f\n", distance); obstacle=0; break;}
                else
                        continue;
        }
 
//check left
else if(degree>-135 && degree<-30)
        {
            if (distance < Boundary_Distance && distance >0)
                        { printf("distance : %f\n", distance); obstacle=2; break;}
                else
                        continue;
        }

        
     }

 fp=fopen("/home/motor/test.txt","w");
    fprintf(fp,"%d",obstacle);
    printf("check:%d\n", obstacle);
    fclose(fp);

}
 
int main(int argc, char **argv)
{
    ros::init(argc, argv, "ydlidar_client");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scanCallback);
    ros::spin();
 
    return 0;
}       