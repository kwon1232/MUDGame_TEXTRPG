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

#define col GetStdHandle(STD_OUTPUT_HANDLE)				// 함수정의
#define BCK SetConsoleTextAttribute(col, 0x0000);		// 검은색
#define WHITE SetConsoleTextAttribute(col, 0x000f);		// 흰색
#define HIG SetConsoleTextAttribute(col, 0x000d);		// 형광
#define BW SetConsoleTextAttribute(col, 0x00f0);		// 검흰색
#define RED SetConsoleTextAttribute(col, 0x000c);		// 빨강
#define VIO SetConsoleTextAttribute(col,0x00f1 | 0x000c | 0x000c);	//보라
#define YEL SetConsoleTextAttribute(col, 0x000e);		// 노란색
#define SKY SetConsoleTextAttribute(col, 0x000b);		// 하늘색
#define S SetConsoleTextAttribute(col, 0x0003);			// 옥색
#define GRAY SetConsoleTextAttribute(col,0x0008);		// 회색
#define HIGH SetConsoleTextAttribute(col, 0x00a);		// 연두
#define DA SetConsoleTextAttribute(col, 0x06a);			// 색연두
#define WHITE1 SetConsoleTextAttribute(col, 0x007);		// 흰색
#define BULE SetConsoleTextAttribute(col, 0x009);		// 파랑
#define BRED SetConsoleTextAttribute(col, 0x0cc);		// 검붉은색
#define BGRAY SetConsoleTextAttribute(col, 0x080);		// 진회색
#define G SetConsoleTextAttribute(col, 0x004);			// 갈색
#define GREEN SetConsoleTextAttribute(col, 0x002);		// 녹색	