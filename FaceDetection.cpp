#include "Logger/Logger.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <map>

using namespace DebugTools;
using namespace cv;
using namespace std;


void PrintFPSCounter()
{
//#include "opencv2/core/utility.hpp"
	int64 start = getTickCount();
	double fps = getTickFrequency() / (getTickCount() - start);
	std::cout << "FPS : " << fps << std::endl;
}

void CameraTest()
{
    VideoCapture cap(0);
	cap.set(CAP_PROP_BRIGHTNESS, 1);
    Mat img;
    while (true)
    {
        cap.read(img);
        imshow("Video", img);
        waitKey(20);
    }
}

void CameraFaceDetector()
{
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
    if (faceCascade.empty())
        cout << "faceCascade XML error !!!" << endl;

    vector<Rect> faces;
    VideoCapture cap(0);

    //cap.set(CAP_PROP_FRAME_WIDTH, 640);
    //cap.set(CAP_PROP_FRAME_HEIGHT, 480);
    
    cap.set(CAP_PROP_BRIGHTNESS, 1);
    Mat img;
    map<int, string> fpsList;
    
    int videoWidth = (int)cap.get(CAP_PROP_FRAME_WIDTH);
    int videoHeight = (int)cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "w= " << videoWidth << " h= " << videoHeight <<endl;
    while (true)
    {
        cap.read(img);

        faceCascade.detectMultiScale(img, faces, 1.1, 10);
        for (int i = 0; i < faces.size(); ++i)
        {
            rectangle(img, faces[i], Scalar(0, 255, 0), 2);
        }

        int fps = (int)cap.get(CAP_PROP_FPS);
        if(fpsList.find(fps) == fpsList.end())
		{
			char* buff = new char[8];
			sprintf(buff, "FPS: %02i", fps);
			fpsList[fps] = string(buff);
		}
		putText(img, fpsList[fps], Point(videoWidth - 50, videoHeight - 5), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(0, 255, 0));
		
		imshow("Video", img);
        waitKey(1);
    }
}

void DrawShapeText()
{
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
    circle(img, Point(256, 256), 150, Scalar(0, 70, 255), FILLED);
    rectangle(img, Rect(Point(100, 100), Point(400, 400)), Scalar(255, 0, 255), 2);
    line(img, Point(10, 500), Point(500, 500), Scalar(255, 0, 0), 3);
    putText(img, "Text String", Point(50, 500), FONT_HERSHEY_COMPLEX, 2, Scalar(0, 255, 0));

    imshow("Image", img);
}


int main()
{
	Logger::Log("Start\n");
	//DrawShapeText();
	//CameraTest();
	CameraFaceDetector();	
	
	waitKey(0);
}
