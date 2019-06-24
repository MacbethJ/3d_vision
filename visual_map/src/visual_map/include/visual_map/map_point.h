#pragma once
#include "visual_map/visual_map_common.h"

namespace vm{
    class Frame;
    class TrackItem{
    public:
        std::shared_ptr<Frame> frame;
        int kp_ind;
        void getUV(float& x, float& y, int& octave);
    };
    
    class MapPoint{
    public:
        int id=-1;
        Eigen::Vector3d position;
        std::vector<TrackItem> track;
    };

}