#include <stdio.h>
#include <windows.h>

int main() {
	system("mode con cols=50 lines=50");
	int UserOrder = 0;
	int StartOrder = 0;

	if (StartOrder == 0) {
		printf("==================================================\n\n");
		printf(" ffffff ll        aaa     ppppp    ppppp   y    y\n");
		printf(" ff     ll       aa  aa   pp   pp  pp   pp  y  y \n");
		printf(" ff     ll      aa    aa  pp   pp  pp   pp   yy  \n");
		printf(" ffffff ll      aaaaaaaa  ppppp    ppppp     yy  \n");
		printf(" ff     ll      aa    aa  pp       pp        yy  \n");
		printf(" ff     lllllll aa    aa  pp       pp        yy  \n\n");
		printf(" bbbbb      iiiiii    rrrrrr      dddddd          \n");
		printf(" bb   bb      ii      rr   rr     dd    dd        \n");
		printf(" bbbbb        ii      rr   rr     dd     dd       \n");
		printf(" bb   bb      ii      rrrrr       dd     dd       \n");
		printf(" bb   bb      ii      rr  rr      dd    dd        \n");
		printf(" bbbbb      iiiiii    rr    rr    dddddd          \n");
		printf("==================================================\n\n");
		printf("    1. 게임 시작   2. 순위 확인   3. 게임 종료\n\n");
		printf("                 --> ");
		scanf_s("%d", &UserOrder);

		//사용자가 1을 눌렀을 때 게임 시작
		if (UserOrder == 1) {
			printf("로  딩  중....");
			Sleep(1000);
			system("cls"); //32번 줄 다음으로 게임 진행 코드 입력하면 됨
		}
		//2를 눌렀을 때 순위 확인
		if (UserOrder == 2) {
			system("cls");
			printf("==================================================\n\n");
			printf("              순                위                 \n\n\n");
		}
		//3을 눌렀을 때 게임 종료
		if (UserOrder == 3) {
			system("cls");
			printf("게임을 종료합니다.\n");
			exit(1);
		}
	}
}
