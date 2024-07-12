#include "Framework.h"

void SetColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서의 x,y 위치를 알려주는 함수
COORD GetXY()
{
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO	curInfor;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	pos.X = curInfor.dwCursorPosition.X;
	pos.Y = curInfor.dwCursorPosition.Y;

	printf("x : %d \ny : %d", pos.X, pos.Y);


	return pos;
}


void PrintIntroMenu()
{
	int POS = 4;	//0 - 새로 하기, 1 - 이어 하기, 2 - 랭킹 보기, 3 - 게임 종료 TEXT RPG
	CursorView(0);
	system("COLOR 5F");
	system("mode con: cols=110 lines=25");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	printf("■                                                                                                          ■");
	printf("■                                                                                                          ■");
	printf("■                                                                                                          ■");
	printf("■                                                                                                          ■");
	printf("■                                                                                                          ■");
	printf("■                                                                                                          ■");
	printf("■                                                                                                          ■");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
	
	printf("\n※※※※※※ ※※※※※   ※※※    ※※※  ※※※※※※    ※※※※※※    ※※※※※※    ※※※※※  \n");
	printf("    ※※     ※※           ※※   ※※         ※※        ※※      ※※  ※※    ※※  ※※      ※※\n");
	printf("    ※※     ※※            ※※ ※※          ※※        ※※      ※※  ※※     ※※ ※※       ※※\n");
	printf("    ※※     ※※※※※        ※※             ※※        ※※     ※※   ※※    ※※  ※※       \n");
	printf("    ※※     ※※            ※※ ※※          ※※        ※※   ※※     ※※※※※    ※※    ※※※ \n");
	printf("    ※※     ※※          ※※     ※※        ※※        ※※     ※※   ※※           ※※     ※ \n");
	printf("    ※※     ※※※※※  ※※※     ※※※      ※※        ※※     ※※   ※※             ※※※※ \n");

	gotoxy(10, 4); printf("새로  하기");
	gotoxy(35, 4); printf("이어  하기");
	gotoxy(60, 4); printf("랭킹  보기");
	gotoxy(85, 4); printf("게임  종료");
	
	while (true) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 3;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 3) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (POS) {
		case 0:
			SetColor(11,5);
			gotoxy(10, 4); printf("새로  하기");
			SetColor(15,5);
			gotoxy(35, 4); printf("이어  하기");
			gotoxy(60, 4); printf("랭킹  보기");
			gotoxy(85, 4); printf("게임  종료");
			break;
		case 1:
			gotoxy(10, 4); printf("새로  하기");
			SetColor(11, 5);
			gotoxy(35, 4); printf("이어  하기");
			SetColor(15, 5);
			gotoxy(60, 4); printf("랭킹  보기");
			gotoxy(85, 4); printf("게임  종료");
			break;
		case 2:
			gotoxy(10, 4); printf("새로  하기");
			gotoxy(35, 4); printf("이어  하기");
			SetColor(11,5);
			gotoxy(60, 4); printf("랭킹  보기");
			SetColor(15,5);
			gotoxy(85, 4); printf("게임  종료");
			break;
		case 3:
			gotoxy(10, 4); printf("새로  하기");
			gotoxy(35, 4); printf("이어  하기");
			gotoxy(60, 4); printf("랭킹  보기");
			SetColor(11, 5);
			gotoxy(85, 4); printf("게임  종료");
			SetColor(15, 5);
			break;
		default: break;
		}
		Sleep(100);
	}
	system("cls");
	if (POS == 0) printf("새로 하기를 눌렀습니다.");
	else if (POS == 1) printf("이어 하기를 눌렀습니다.");
	else if (POS == 2) printf("랭킹 보기를 눌렀습니다.");
}

