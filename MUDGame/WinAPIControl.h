#pragma once



typedef struct VECTOR2
{
	double x;
	double y;
}vector2;

typedef vector2 Vector2;


void CursorView(char show);

// 커서 위치를 x y로 변경하는 함수
void GotoXY(int x, int y);

int ControlKey();

COORD GetXY();

