#include "visual_map/frame.h"

namespace vm{
    Eigen::Matrix4d Frame::getPose(){
        Eigen::Matrix3d temp_rot(direction);
        Eigen::Matrix4d temp_pose= Eigen::Matrix4d::Identity();
        temp_pose.block(0,0,3,3)=temp_rot;
        temp_pose.block(0,3,3,1)=position;
        return temp_pose;
    }
    
    void Frame::setPose(Eigen::Matrix4d pose){
        position=pose.block(0,3,3,1);
        Eigen::Matrix3d tempRot = pose.block(0,0,3,3);
        Eigen::Quaterniond temp_qua(tempRot);
        direction=temp_qua;
    }
    
    Eigen::Matrix<double,3, 4> Frame::getProjMat(){
        Eigen::Matrix<double,3, 4> k_mat=Eigen::Matrix<double,3, 4>::Zero();
        k_mat(0,0)=fx;
        k_mat(1,1)=fy;
        k_mat(0,2)=cx;
        k_mat(1,2)=cy;
        k_mat(2,2)=1;
        Eigen::Matrix<double,3, 4> proj=k_mat*getPose().inverse();
        return proj;
    }
    
}

