enum GameState
{
	Intro,
	Quit,
};

// Player

enum Color {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKY_BLUE,
	DARK_RED,
	DARK_VOILET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKY_BLUE,
	RED,
	VIOLET,
	TELLOW,
	WHITE,
};

#define col GetStdHandle(STD_OUTPUT_HANDLE)				// �Լ�����
#define BCK SetConsoleTextAttribute(col, 0x0000);		// ������
#define WHITE SetConsoleTextAttribute(col, 0x000f);		// ���
#define HIG SetConsoleTextAttribute(col, 0x000d);		// ����
#define BW SetConsoleTextAttribute(col, 0x00f0);		// �����
#define RED SetConsoleTextAttribute(col, 0x000c);		// ����
#define VIO SetConsoleTextAttribute(col,0x00f1 | 0x000c | 0x000c);	//����
#define YEL SetConsoleTextAttribute(col, 0x000e);		// �����
#define SKY SetConsoleTextAttribute(col, 0x000b);		// �ϴû�
#define S SetConsoleTextAttribute(col, 0x0003);			// ����
#define GRAY SetConsoleTextAttribute(col,0x0008);		// ȸ��
#define HIGH SetConsoleTextAttribute(col, 0x00a);		// ����
#define DA SetConsoleTextAttribute(col, 0x06a);			// ������
#define WHITE1 SetConsoleTextAttribute(col, 0x007);		// ���
#define BULE SetConsoleTextAttribute(col, 0x009);		// �Ķ�
#define BRED SetConsoleTextAttribute(col, 0x0cc);		// �˺�����
#define BGRAY SetConsoleTextAttribute(col, 0x080);		// ��ȸ��
#define G SetConsoleTextAttribute(col, 0x004);			// ����
#define GREEN SetConsoleTextAttribute(col, 0x002);		// ���	