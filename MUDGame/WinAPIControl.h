#pragma once



typedef struct VECTOR2
{
	double x;
	double y;
}vector2;

typedef vector2 Vector2;


void CursorView(char show);

// Ŀ�� ��ġ�� x y�� �����ϴ� �Լ�
void GotoXY(int x, int y);

int ControlKey();

COORD GetXY();

