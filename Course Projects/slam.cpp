#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>

#include<opencv2/core/core.hpp>

#include<System.h>

using namespace std;

void LoadImages(const string &strFile, vector<string> &vstrImageFilenames,
                vector<double> &vTimestamps);

int main(int argc, char ** argv)
{
	
    vector<string> vstrImageFilenames;
    cv::VideoCapture vc(argv[1]);
    std::ifstream in_data(argv[3]);
    std::string str;
    cv::Mat im;


    ORB_SLAM2::System SLAM(argv[1],argv[2],ORB_SLAM2::System::MONOCULAR,true);

    vector<float> vTimesTrack;

	cout << endl << "-------" << endl;
    cout << "Start processing sequence ..." << endl;

    for(int ni=0; ni<1000000; ni++)
    {
        vc >> im;
        in_data >> str;
	


        // Pass the image to the SLAM system
        SLAM.TrackMonocular(im,tframe);


    }

    SLAM.Shutdown();

    // Tracking time statistics
    sort(vTimesTrack.begin(),vTimesTrack.end());

    // Save camera trajectory
    SLAM.SaveKeyFrameTrajectoryTUM("KeyFrameTrajectory.txt");

    return 0;

}
