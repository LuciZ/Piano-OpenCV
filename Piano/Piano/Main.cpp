#include "Piano.h"
using namespace std;

int main()
{
	Piano piano;

	// �̸� ����
	piano.putFinger(4);
	piano.putFinger(5);
	piano.putFinger(6);
	// ȭ�鿡 ���
	piano.renderPiano();


	waitKey();
	
	return 0;
}