#include"Warping.h"

Mat Warping::GetMappedImage(const Mat& inImage, const Mat& inCanvas, PointList inLocationPointsClockwise) {
	Mat mMappedImage(inCanvas);
	Warping warping(inImage, inCanvas, inLocationPointsClockwise);
	warping.MapImageToCanvas(mMappedImage);
	return mMappedImage;
}

Warping::Warping(const Mat& inImage, const Mat& inCanvas, PointList inLocationPointsClockwise)
	:mImage(inImage), mCanvas(inCanvas), 
	 mLocationPointsClockwise(inLocationPointsClockwise) {
}

Warping::~Warping() {}

void Warping::MapImageToCanvas(Mat& mMappedImage) {
	Mat mWarpedImage, mask;
	ApplyWarpingMatrix(mWarpedImage);
	cvtColor(mWarpedImage, mask, CV_RGB2GRAY);
	threshold(mask, mask, 80, 255, THRESH_BINARY);
	mWarpedImage.copyTo(mMappedImage, mask);

}

void Warping::ApplyWarpingMatrix(Mat& mWarpedImage) {
	Mat mWarpingMatrix;
	GetWarpingMatrix(mWarpingMatrix);
	warpPerspective(mImage, mWarpedImage, mWarpingMatrix, Size(mCanvas.cols, mCanvas.rows));
}

void Warping::GetWarpingMatrix(Mat& mWarpingMatrix) {
	PointList mImagePointsClockwise;
	SetImagePointsClockwise(mImagePointsClockwise);
	mWarpingMatrix = getPerspectiveTransform(mImagePointsClockwise, mLocationPointsClockwise);
}

void Warping::SetImagePointsClockwise(PointList& mImagePointsClockwise) {
	mImagePointsClockwise.push_back(Point2f(0.0, 0.0));
	mImagePointsClockwise.push_back(Point2f(mImage.cols - 1, 0.0));
	mImagePointsClockwise.push_back(Point2f(mImage.cols - 1, mImage.rows - 1));
	mImagePointsClockwise.push_back(Point2f(0.0, mImage.rows - 1));
}