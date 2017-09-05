#pragma once
#include<opencv2\opencv.hpp>
#include<vector>

using namespace std;
using namespace cv;

typedef vector<Point2f> PointList;

class Warping {
public:
	static Mat GetMappedImage(const Mat& inImage, const Mat& inCanvas, PointList inLocationPoints);
private:
	Warping(const Mat& inImage, const Mat& inCanvas, PointList inLocationPoints);
	~Warping();
	void MapImageToCanvas(Mat& mMappedImage);
	void ApplyWarpingMatrix(Mat& mWarpedImage);
	void GetWarpingMatrix(Mat& mWarpingMatrix);
	void SetImagePointsClockwise(PointList& mImagePoints);

	Mat mImage;
	Mat mCanvas;
	PointList mLocationPointsClockwise;
};