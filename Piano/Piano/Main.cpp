#include "Piano.h"
#include "music_sheet.h"
#include "FaceDetector.h"
using namespace std;

// ���� �����. 10�̸� 10�����Ӵ� �� ���� �����.
const int PLAY_RATE = 10;

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
	for (int i = 0; i < 9 * PLAY_RATE; i++)
	{
		cv::Mat temp_Map = piano_view(next_page, index, piano_map);

		// �ǾƳ� ���
		if (i % PLAY_RATE == 0)
		{
			piano.putFinger(notes[i / PLAY_RATE]);
		}
		piano.renderPiano(temp_Map);
		waitKey(1);
		
		// �ǾƳ� ���
		if (i % PLAY_RATE == PLAY_RATE - 1)
		{
			piano.releaseFinger(notes[i / PLAY_RATE]);
		}


		if (!detector.detect(tmpX))
			cout << "qwer";
	
	}

	waitKey();

	return 0;
}