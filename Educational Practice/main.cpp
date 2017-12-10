//#include <vector>
//#include <chrono>
//#include <sys/time.h>
//#include <iostream>
//#include <vector>
//#include <assert.h>
//#include <sys/mman.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <cassert>
//#include <string>
//#include <algorithm>

//std::string output = "";

//std::vector<std::pair<int,int>> get_team_ratings(const std::string & prefix)
//{

//}

//bool compare_teams (const std::pair<int,int> & a,const std::pair<int,int> & b)
//{
//    return (a.second_type-b.second_type) > 0;
//}

//void erase_one_team(std::vector<std::pair<int,int>> & team_ratings)
//{

//}

//void print_res(const std::string & prefix,std::vector<std::pait<int,int>> & teams_ratings)
//{
//    for (int i = 0; i < teams_ratings; i+=2)
//    {

//    }

//}

//int main()
//{
//    std::vector<std::string> prefixes = {};
//    for (auto prefix : prefixes)
//    {
//        std::vector<std::pair<int,int>> team_ratings = get_team_ratings(prefix);
//        std::sort(team_ratings.begin(), team_ratings.end(), compare_teams);
//        if (team_ratings.size()%2 == 1)
//            erase_one_team(team_ratings);
//        print_res(prefix,team_ratings);
//    }
//}


#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utils/trace.hpp>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <dirent.h>

static void getMaxClass(const cv::Mat &probBlob, int * classId, double * classProb)
{
    cv::Mat probMat = probBlob.reshape(1, 1);
    cv::Point classNumber;

    cv::minMaxLoc(probMat, NULL, classProb, &classNumber);
    *classId = classNumber.x;
}


int main()
{
    std::string modeltxt = "/home/apletea/PycharmProjects/untitled1/posters/deploy.prototxt";
    std::string modelBin = "/home/apletea/PycharmProjects/untitled1/posters/snapshot_iter_18200.caffemodel";
    std::string file_path = "/home/apletea/PycharmProjects/untitled1/false/";
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(modeltxt, modelBin);

    std::map<int,double> mp;
    DIR *dir;
    struct dirent *ent;
    dir = opendir(file_path.data());
    while ((ent = readdir(dir)) != NULL)
    {
        cv::Mat img;
        img = cv::imread(file_path+ent->d_name);
        if (!img.data)
            continue;
        cv::Mat inputblob = cv::dnn::blobFromImage(img,1,cv::Size(224,224), cv::Scalar(104, 117, 123));
        cv::Mat prob;
        net.setInput(inputblob,"data");
        prob = net.forward("");

        int classId;
        double classProb;
        getMaxClass(prob, &classId, &classProb);
        std::string name = ent->d_name;
        std::string id = name.substr(0,name.size()-4);
        std::cout << id << std::endl;
        if (classId == 0)
            mp[std::stoi(name)] = 1 - classProb;
        else
            mp[std::stoi(name)] = classProb;
        std::cout << classId << std::endl;
        cv::waitKey(1);
    }
    std::ofstream out("/home/apletea/PycharmProjects/untitled1/img_test.csv");
    out << "Id,Prob" << std::endl;
    for (int i = 3636; i < 4544; ++i)
    {
        out << i << "," << mp[i]<< std::endl;
    }

}
































