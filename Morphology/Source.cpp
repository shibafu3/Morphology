#ifdef _DEBUG
//Debugモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300d.lib")            // opencv_core
#else
//Releaseモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300.lib") 
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
/*数値計算ライブラリ*/
#define _USE_MATH_DEFINES
#include <math.h>
/*可変長リストライブラリ*/
#include <vector>
/*OpenCVライブラリ*/
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include "opencv/cv.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/opencv.hpp"
#include "opencv2/superres/optical_flow.hpp"
#include <vector>


using namespace std;
using namespace cv;


int main(){
	Mat image = imread("C:\\Users\\0133752\\Desktop\\mor1.png");
	Mat kouzou(Size(3, 3), CV_8SC1, Scalar::all(1));
	imwrite("C:\\Users\\0133752\\Desktop\\dest.png", image);

	imshow("", image);
	waitKey(0);
	morphologyEx(image, image, CV_MOP_CLOSE, kouzou, Point(-1, -1), 3);
	imwrite("C:\\Users\\0133752\\Desktop\\dest1.png", image);
	//MORPH_ERODE　　　結果はerode()と同様
	//	MORPH_DILATE　　 　結果はdilate()と同様
	//	MORPH_OPEN　　　　オープニング
	//	MORPH_CLOSE　　　 クロージング
	//	MORPH_GRADIENT　 モルフォロジー勾配(エッジ検出)
	//	MORPH_TOPHAT　　　トップハット
	//	MORPH_BLACKHAT　 ブラックハットe

	imshow("", image);
	waitKey(0);

	morphologyEx(image, image, CV_MOP_OPEN, kouzou, Point(-1, -1), 1);
	imwrite("C:\\Users\\0133752\\Desktop\\dest2.png", image);
	imshow("", image);
	waitKey(0);


	morphologyEx(image, image, MORPH_DILATE, kouzou, Point(-1, -1), 4);
	imwrite("C:\\Users\\0133752\\Desktop\\dest3.png", image);
	imshow("", image);
	waitKey(0);
}