#include <iostream>
#include <fstream>
#include <chrono>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
using namespace std::chrono;

int convert_r(int o_max, int o_min, int n_max, int n_min, int val){
    return (int)(((val - o_min) * (n_max - n_min)) / (o_max - o_min)) + n_min;
}

int main()
{
    //FILE on_file;
    char c[10] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    char c_e[70] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v',
                    'u','n','x','r','j','f','t','/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','"','^','`','\'','.',' '};
    
    VideoCapture cap;

    cap.open(1);
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 360);


    if (!cap.isOpened())
    {
        cout << "Video capture is not open!" << endl;
        return -1;
    }
    

    Mat frameRGB, r_frameGS;
    //ofstream ofs ("img.txt", ofstream::out);
    int i = 0;
    while (true)
    {
        stringstream f;
        //i++;
        auto t1 = high_resolution_clock::now();;
        auto t2 = high_resolution_clock::now();;
        cap.read(frameRGB);
        if (frameRGB.empty())
        {
            cout << "Couldn't grab frame!" << endl;
            break;
        }
        cvtColor(frameRGB, r_frameGS, COLOR_RGB2GRAY);
        resize(r_frameGS, r_frameGS, Size(200, 50), INTER_LINEAR);

        //t1 = high_resolution_clock::now();
        for (int i = 0; i < r_frameGS.rows; i++)
        {
            //ofs << endl;
            f << endl;
            for (int j = 0; j < r_frameGS.cols; j++)
            {
                int l = (int)r_frameGS.at<uchar>(i,j);
                //ofs << c[convert_r(255, 0, 0, 9, l)];
                f << c[convert_r(255, 0, 9, 0, l)];
                //f << c_e[convert_r(255, 0, 0, 70, l)];
            }
        }
        //t2 = high_resolution_clock::now();
        system("cls");
        cout << f.str();
	    
        //duration<double, std::milli> ms_double = t2 - t1;
	    //cout << ms_double.count() << "ms";
        
        //imshow("Cam 0", r_frameGS);
        //if(waitKey(5) >= 0)
        //    break;
    }
    //ofs.close();
    return 0;
}
