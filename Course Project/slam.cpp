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
    std::ifstream in_data(argv[2]);
    std::string str;
//    LoadImages(strFile, vstrImageFilenames, vTimestamps);
    int nImages = 1;
    cv::Mat im;


    ORB_SLAM2::System SLAM(argv[3],argv[2],ORB_SLAM2::System::MONOCULAR,true);

    vector<float> vTimesTrack;

	cout << endl << "-------" << endl;
    cout << "Start processing sequence ..." << endl;

    for(int ni=0; ni<1000000; ni++)
    {
        vc >> im;
        std::cout << "get frame" << std::endl;
        in_data >> str;
	    double tframe;
	

#ifdef COMPILEDWITHC11
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
#else
        std::chrono::monotonic_clock::time_point t1 = std::chrono::monotonic_clock::now();
#endif

        // Pass the image to the SLAM system
        SLAM.TrackMonocular(im,tframe);
        std::cout << "TrackMonocular" << std::endl;


#ifdef COMPILEDWITHC11
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
#else
        std::chrono::monotonic_clock::time_point t2 = std::chrono::monotonic_clock::now();
#endif

        double ttrack= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();

        // Wait to load the next frame
      //  double T=0;
      //  if(ni<nImages-1)
      //      T = vTimestamps[ni+1]-tframe;
      //  else if(ni>0)
      //      T = tframe-vTimestamps[ni-1];

      // if(ttrack<T)
      //      usleep((T-ttrack)*1e6);
        nImages = ni;
    }

    SLAM.Shutdown();

    // Tracking time statistics


    // Save camera trajectory
    SLAM.SaveKeyFrameTrajectoryTUM("KeyFrameTrajectory.txt");

    return 0;

}
