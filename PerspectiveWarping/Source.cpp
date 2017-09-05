#include"Warping.h"

int main() {
	Mat inImage = imread("word.bmp");
	Mat inCanvas = imread("test3.jpg");
	PointList inLocationPoints;
	inLocationPoints.push_back(Point2f(1437,1077));
	inLocationPoints.push_back(Point2f(3005, 901));
	inLocationPoints.push_back(Point2f(2813, 2885));
	inLocationPoints.push_back(Point2f(1417, 2257));
	Mat result = Warping::GetMappedImage(inImage, inCanvas, inLocationPoints);
	imwrite("result3.jpg", result);
	return 0;
}