#include <stdio.h>
#include <windows.h>
#include<stdbool.h>
#include <conio.h>

#define bird_head 18
#define bird_bottom_y 18

void GotoXY(int x, int y) //커서의 위치를 x, y로 이동하는 함수
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {            //키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
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
	int End = 0; //마지막 장애물에 닿거나 떨어졌을 때 End++로 게임 종료시킬 변수
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
		printf("    1. 게임 시작   2. 순위 확인   3. 게임 종료\n\n");
		printf("                 --> ");
		scanf_s("%d", &UserOrder);

		//2를 눌렀을 때 순위 확인
		if (UserOrder == 2) {
			system("cls");
			printf("==================================================\n\n");
			printf("              순                위                \n\n\n");
		}

		//3을 눌렀을 때 게임 종료
		if (UserOrder == 3) {
			system("cls");
			printf("\n\n\n\n\n               게임을 종료합니다.            \n\n\n\n");
			exit(1);
			system("cls");
		}

		//사용자가 1을 눌렀을 때 게임 시작
		if (UserOrder == 1) {
			printf("로  딩  중....");
			Sleep(1000);
			system("cls"); //해당 줄 다음으로 게임 진행 코드 입력하면 됨

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

				//점프 중 = y값 감소
				//점프 끝 = y값 증가
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
				Sleep(80);  //점프 속도 조절
				system("cls");    //창 클리어 나중에 써먹을 예정
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