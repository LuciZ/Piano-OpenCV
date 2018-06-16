#include "Piano.h"
#include "music_sheet.h"
#include "FaceDetector.h"
using namespace std;

int main()
{
	int notes[] = {
		0, 4, 7, 12, 16, 12, 7, 4, 0
	};

	Piano piano;
	vector<cv::Mat> piano_map;
	string input_file = "twinkle_twinkle";
	bool next_page = false;
	int index = 0;
	//piano_map_init_video(piano_map);//camera capture Ver

	//�ո����߰�
	//���ν��� ���� Ŭ����
	FaceDetector detector;

	piano_map_init_DB(input_file, piano_map); // DB(����)Ver

	//�����쿡 �ݹ��Լ��� ���
	cv::setMouseCallback(PROJECT_NAME, CallBackFunc, NULL);
	int tmpX = 0;
	for (int i = 0; i < 9; i++)
	{
		cv::Mat temp_Map = piano_view(next_page, index, piano_map);

		//piano.putFinger(rand() % PIANO_SIZE);
		piano.putFinger(notes[i]);
		piano.renderPiano(temp_Map);
		waitKey(1);
		//piano.releaseFinger(rand() % PIANO_SIZE);
		piano.releaseFinger(notes[i]);
		if (!detector.detect(tmpX))
			cout << "qwer";
	
	}

	waitKey();

	return 0;
}