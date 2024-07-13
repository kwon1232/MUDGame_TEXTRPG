#pragma once



typedef struct VECTOR2
{
	double x;
	double y;
}vector2;

typedef vector2 Vector2;


void SetColor(int foreground, int background);

void CursorView(char show);

void gotoxy(int x, int y);

COORD GetXY();

void PrintIntroMenu();