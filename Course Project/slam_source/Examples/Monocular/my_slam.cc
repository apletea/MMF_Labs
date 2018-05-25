#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>

#include<opencv2/core/core.hpp>

#include<System.h>
#include<vector>

void LoadImages(const string &strFile, vector<string> &vstrImageFilenames,
                vector<double> &vTimestamps);
std::vector<int> convert2Vec(std::string str);
int main(int argc, char ** argv)
{
	
    vector<string> vstrImageFilenames;
    cv::VideoCapture vc(argv[1]);
    std::ifstream in_data(argv[4]);
    std::string str;
    int nImages = 1;
    cv::Mat im;
    std::vector<int> sensors;

    ORB_SLAM2::System SLAM(argv[3],argv[2],ORB_SLAM2::System::SENSORS,true);
    SLAM.mbActivateLocalizationMode = true;
    std::vector<float> vTimesTrack;

    std::cout << std::endl << "-------" << std::endl;
    std::cout << "Start processing sequence ..." << std::endl;

    for(int ni=0; ni<1000000; ni++)
    {
        vc >> im;
        cv::rotate(im, im, cv::ROTATE_90_CLOCKWISE);
        std::cout << "get frame" << std::endl;
	    double tframe;
	    sensors = convert2Vec(in_data);

        // Pass the image to the SLAM system
        SLAM.TrackSensor(im,sensors,tframe);
        std::cout << "TrackMonocular" << std::endl;

        double ttrack= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        nImages = ni;
    }

    SLAM.Shutdown();

    SLAM.SaveKeyFrameTrajectoryTUM("KeyFrameTrajectory.txt");

    return 0;

}


std::vector<int> convert2Vec(std::ifstream stream)
{
    std::vector<int> ans;
    int tmp;
    for (int i = 0; i < 6; ++i)
    {
        stream >> tmp;
        ans.push_back(tmp);
    }
    return ans;
}
