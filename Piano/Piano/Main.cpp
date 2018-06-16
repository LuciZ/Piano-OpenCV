#include "Piano.h"
#include "music_sheet.h"
#include "FaceDetector.h"
#include "Handrecognition.h"

using namespace std;

// ���� �����. 10�̸� 10�����Ӵ� �� ���� �����.
const int PLAY_RATE = 10;
int NOW_RATE = 0;

int main()
{
	Leap::Controller controller;

	// paste the listener
	MyListener listener;
	controller.addListener(listener);

	Piano piano;
	vector<cv::Mat> piano_map;
	string input_file = "twinkle_twinkle";

	bool next_page = false;
	int index = 0;

	piano_map_init_video(piano_map);//camera capture Ver

	//�ո����߰�
	//���ν��� ���� Ŭ����
	FaceDetector detector;

	piano_map_init_DB(input_file, piano_map); // DB(����)Ver

	//�����쿡 �ݹ��Լ��� ���
	cv::setMouseCallback(PROJECT_NAME, CallBackFunc, NULL);

	int tmpX = 0;

	cout << "start the piano system" << endl;

	while (listener.isEnable())
	{
		next_page = detector.detect(tmpX);

		if (next_page)
			cout << "�ѱ�" << endl;

		cv::Mat temp_Map = piano_view(next_page, index, piano_map);

		// �ǾƳ� ���
		// �� ����
		piano.putFinger(listener.pressNotes());

		piano.renderPiano(temp_Map);
		waitKey(1);
		
		// �ǾƳ� ���
		if (listener.isNoteChanged())
			piano.releaseFinger(listener.realeaseNotes());
	}

	// remove listener before exit program.
	controller.removeListener(listener);

	return 0;
}