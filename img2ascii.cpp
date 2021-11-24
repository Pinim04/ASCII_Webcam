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

    //Luminance scale in ASCII
    char c[10] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    //char c_e[70] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v',
    //                'u','n','x','r','j','f','t','/','\\','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','"','^','`','\'','.',' '};
    
    //Get video capture from webcam
    VideoCapture cap;
    cap.open(1);    //The index could be different, see openCV documentation fot further informations
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 360);

    //Chech if the video stream from the webcam is alive
    if (!cap.isOpened())
    {
        cout << "Video capture is not open!" << endl;
        return -1;
    }
    
    //Define Mat for frame in RBG and in GrayScale
    Mat frameRGB, r_frameGS;
    
    //ofstream ofs ("img.txt", ofstream::out);
    
    while (true)
    {
        stringstream f;
        
        //std::chrono methods to test the framerate
        //auto t1 = high_resolution_clock::now();;
        //auto t2 = high_resolution_clock::now();;
        
        //Read new frame from video capture
        cap.read(frameRGB);

        //Chech if frame was captured successfully
        if (frameRGB.empty())
        {
            cout << "Couldn't grab frame!" << endl;
            break;
        }

        //Convert frame RBG to GrayScale
        cvtColor(frameRGB, r_frameGS, COLOR_RGB2GRAY);
        //Resize frame to fit in terminal window
        resize(r_frameGS, r_frameGS, Size(200, 50), INTER_LINEAR);

        //Get first timestamp
        //t1 = high_resolution_clock::now();
        
        for (int i = 0; i < r_frameGS.rows; i++)
        {
            //ofs << endl;
            f << endl;
            for (int j = 0; j < r_frameGS.cols; j++)
            {
                //Get luminance value from every pixel of the frame
                int l = (int)r_frameGS.at<uchar>(i,j);
                //ofs << c[convert_r(255, 0, 0, 9, l)];

                //Write to stringstream the correspondent ASCII character to the luminance value
                f << c[convert_r(255, 0, 9, 0, l)];
                //f << c_e[convert_r(255, 0, 0, 70, l)];
            }
        }

        //Get second timestamp
        //t2 = high_resolution_clock::now();

        //Clear the screen before printing new frame
        system("cls");
        cout << f.str();
	    
        //duration<double, std::milli> ms_double = t2 - t1;
	    //cout << ms_double.count() << "ms";
    }

    //ofs.close();
    return 0;
}