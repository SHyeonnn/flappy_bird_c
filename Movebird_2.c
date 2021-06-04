#include <stdio.h>
#include <windows.h>
#include<stdbool.h>
#include <conio.h>

#define bird_head 18
#define bird_bottom_y 18

void GotoXY(int x, int y) //Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {            //Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
	if (_kbhit() != 0){
		return _getch();
	}
	return 0;
}

void DrawBird(int bird)
{
	GotoXY(0, bird);
	printf("      ***         \n");
	printf("   *   O *        \n");
	printf("   *     *        \n");
	printf("      ***         \n");
	printf("      L L         \n");
	printf("                  \n");
}

int main() {
	system("mode con cols=50 lines=50");
	int UserOrder = 0;
	int StartOrder = 0;
	int End = 0; //������ ��ֹ��� ��ų� �������� �� End++�� ���� �����ų ����
	int Score = 0;

	if (StartOrder == 0) {
		printf("==================================================\n\n");
		printf(" ffffff ll        aaa     ppppp    ppppp   y    y\n");
		printf(" ff     ll       aa  aa   pp   pp  pp   pp  y  y \n");
		printf(" ff     ll      aa    aa  pp   pp  pp   pp   yy  \n");
		printf(" ffffff ll      aaaaaaaa  ppppp    ppppp     yy  \n");
		printf(" ff     ll      aa    aa  pp       pp        yy  \n");
		printf(" ff     lllllll aa    aa  pp       pp        yy  \n\n");
		printf("   bbbbb      iiiiii    rrrrrr      dddddd       \n");
		printf("   bb   bb      ii      rr   rr     dd    dd     \n");
		printf("   bbbbb        ii      rr   rr     dd     dd    \n");
		printf("   bb   bb      ii      rrrrr       dd     dd    \n");
		printf("   bb   bb      ii      rr  rr      dd    dd     \n");
		printf("   bbbbb      iiiiii    rr    rr    dddddd       \n");
		printf("==================================================\n\n");
		printf("    1. ���� ����   2. ���� Ȯ��   3. ���� ����\n\n");
		printf("                 --> ");
		scanf_s("%d", &UserOrder);

		//2�� ������ �� ���� Ȯ��
		if (UserOrder == 2) {
			system("cls");
			printf("==================================================\n\n");
			printf("              ��                ��                \n\n\n");
		}

		//3�� ������ �� ���� ����
		if (UserOrder == 3) {
			system("cls");
			printf("\n\n\n\n\n               ������ �����մϴ�.            \n\n\n\n");
			exit(1);
			system("cls");
		}

		//����ڰ� 1�� ������ �� ���� ����
		if (UserOrder == 1) {
			printf("��  ��  ��....");
			Sleep(1000);
			system("cls"); //�ش� �� �������� ���� ���� �ڵ� �Է��ϸ� ��

			bool UP = false;
			bool DOWN = true;
			const int gravity = 2;

			int bird = bird_head;

			while (true) {
				Score++;
				if (GetKeyDown() == 'z') {
					UP = true;
					DOWN = false;
				}

				//���� �� = y�� ����
				//���� �� = y�� ����
				if (UP) {
					bird -= gravity*2;
					UP = false;
					DOWN = true;
				}
				else {
					bird += gravity;
					}

				if (bird <= 2) {
					UP = false;
					End++;
				}
				DrawBird(bird);
				Sleep(80);  //���� �ӵ� ����
				system("cls");    //â Ŭ���� ���߿� ����� ����
			}
			system("pause");
		}
	}
	if (End == 1) {
		printf("                                                  \n");
		printf("==================================================\n\n");
		printf("         *****      *     *       * ******        \n");
		printf("        *          * *    * *   * * *             \n");
		printf("        *  ****   *****   *  * *  * *****         \n");
		printf("        *  *  *  *     *  *   *   * *             \n");
		printf("         *****  *       * *       * ******        \n\n");
		printf("            ****  *       ****** ****             \n");
		printf("           *    *  *     * *     *   *            \n");
		printf("           *    *   *   *  ****  ****             \n");
		printf("           *    *    * *   *     * *              \n");
		printf("            ****      *    ***** *   *            \n");
		printf("==================================================\n\n");
	}
}