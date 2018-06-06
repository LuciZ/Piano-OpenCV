#include <opencv2\opencv.hpp>
#include <string>
#include <vector>
#include "Constants.h"
using namespace std;
using namespace cv;

class Piano
{
public:
	Piano();
	~Piano();

	// ȭ�鿡 ǥ��
	void renderPiano();
	// �հ����� �ø�
	void putFinger(int pianoKeyboardIndex);
	// �հ����� ��
	void releaseFinger(int pianoKeyboardIndex);

private:
	Mat pianoImage;
	Mat fingerImage;

	// ���� �ö� �ִ� ��ġ�� ���
	bool isFingerOn[PIANO_SIZE] = { false };
	// �Ͼ� �ǹ��ΰ�
	bool isWhiteKeyboard[PIANO_SIZE] = {
		true, false, true, false, true, true, false, true, false, true, false, true, 
		true, false, true, false, true, true, false, true, false
	};
};

Piano::Piano()
{
	const string pianoFileName = "images/piano.jpg";
	const string fingerFileName = "images/finger.png";

	pianoImage = imread(pianoFileName);
	fingerImage = imread(fingerFileName);

	cout << pianoImage.rows << ' ' << pianoImage.cols << endl;
	cout << fingerImage.rows << ' ' << fingerImage.cols << endl;

	namedWindow(PROJECT_NAME, WINDOW_NORMAL);
	resizeWindow(PROJECT_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
}

Piano::~Piano()
{
}

inline void Piano::renderPiano()
{
	Mat frame = pianoImage;

	// ���� ���� ���� ȭ�鿡 ǥ��
	for (int i = 0; i < PIANO_SIZE; i++)
	{
		if (isFingerOn[i] == false)
		{
			continue;
		}

		int width = i * (pianoImage.cols / PIANO_SIZE);
		int height = pianoImage.rows - fingerImage.rows;

		// �Ͼ� �ǹ�
		if (isWhiteKeyboard[i])
		{			
			frame(cv::Rect(width, height, fingerImage.cols, fingerImage.rows)) -= Scalar(100);
		}
		// ���� �ǹ�
		else
		{
			height -= fingerImage.rows / 3;
			frame(cv::Rect(width, height, fingerImage.cols, fingerImage.rows)) += Scalar(200);
		}
	}

	imshow(PROJECT_NAME, frame);
}

inline void Piano::putFinger(int pianoKeyboardIndex)
{
	isFingerOn[pianoKeyboardIndex] = true;
}

inline void Piano::releaseFinger(int pianoKeyboardIndex)
{
	isFingerOn[pianoKeyboardIndex] = false;
}
