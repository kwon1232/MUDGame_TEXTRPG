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

// Ŀ���� x,y ��ġ�� �˷��ִ� �Լ�
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
	int POS = 4;	//0 - ���� �ϱ�, 1 - �̾� �ϱ�, 2 - ��ŷ ����, 3 - ���� ���� TEXT RPG
	CursorView(0);
	system("COLOR 5F");
	system("mode con: cols=110 lines=25");
	printf("��������������������������������������������������������");
	printf("��                                                                                                          ��");
	printf("��                                                                                                          ��");
	printf("��                                                                                                          ��");
	printf("��                                                                                                          ��");
	printf("��                                                                                                          ��");
	printf("��                                                                                                          ��");
	printf("��                                                                                                          ��");
	printf("��������������������������������������������������������\n\n");
	
	printf("\n�ءءءءء� �ءءءء�   �ءء�    �ءء�  �ءءءءء�    �ءءءءء�    �ءءءءء�    �ءءءء�  \n");
	printf("    �ء�     �ء�           �ء�   �ء�         �ء�        �ء�      �ء�  �ء�    �ء�  �ء�      �ء�\n");
	printf("    �ء�     �ء�            �ء� �ء�          �ء�        �ء�      �ء�  �ء�     �ء� �ء�       �ء�\n");
	printf("    �ء�     �ءءءء�        �ء�             �ء�        �ء�     �ء�   �ء�    �ء�  �ء�       \n");
	printf("    �ء�     �ء�            �ء� �ء�          �ء�        �ء�   �ء�     �ءءءء�    �ء�    �ءء� \n");
	printf("    �ء�     �ء�          �ء�     �ء�        �ء�        �ء�     �ء�   �ء�           �ء�     �� \n");
	printf("    �ء�     �ءءءء�  �ءء�     �ءء�      �ء�        �ء�     �ء�   �ء�             �ءءء� \n");

	gotoxy(10, 4); printf("����  �ϱ�");
	gotoxy(35, 4); printf("�̾�  �ϱ�");
	gotoxy(60, 4); printf("��ŷ  ����");
	gotoxy(85, 4); printf("����  ����");
	
	while (true) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 3;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 3) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//���͸� ������ ��
			break;
		switch (POS) {
		case 0:
			SetColor(11,5);
			gotoxy(10, 4); printf("����  �ϱ�");
			SetColor(15,5);
			gotoxy(35, 4); printf("�̾�  �ϱ�");
			gotoxy(60, 4); printf("��ŷ  ����");
			gotoxy(85, 4); printf("����  ����");
			break;
		case 1:
			gotoxy(10, 4); printf("����  �ϱ�");
			SetColor(11, 5);
			gotoxy(35, 4); printf("�̾�  �ϱ�");
			SetColor(15, 5);
			gotoxy(60, 4); printf("��ŷ  ����");
			gotoxy(85, 4); printf("����  ����");
			break;
		case 2:
			gotoxy(10, 4); printf("����  �ϱ�");
			gotoxy(35, 4); printf("�̾�  �ϱ�");
			SetColor(11,5);
			gotoxy(60, 4); printf("��ŷ  ����");
			SetColor(15,5);
			gotoxy(85, 4); printf("����  ����");
			break;
		case 3:
			gotoxy(10, 4); printf("����  �ϱ�");
			gotoxy(35, 4); printf("�̾�  �ϱ�");
			gotoxy(60, 4); printf("��ŷ  ����");
			SetColor(11, 5);
			gotoxy(85, 4); printf("����  ����");
			SetColor(15, 5);
			break;
		default: break;
		}
		Sleep(100);
	}
	system("cls");
	if (POS == 0) printf("���� �ϱ⸦ �������ϴ�.");
	else if (POS == 1) printf("�̾� �ϱ⸦ �������ϴ�.");
	else if (POS == 2) printf("��ŷ ���⸦ �������ϴ�.");
}

