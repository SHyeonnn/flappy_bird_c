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
		printf("    1. ���� ����   2. ���� Ȯ��   3. ���� ����\n\n");
		printf("                 --> ");
		scanf_s("%d", &UserOrder);

		//����ڰ� 1�� ������ �� ���� ����
		if (UserOrder == 1) {
			printf("��  ��  ��....");
			Sleep(1000);
			system("cls"); //32�� �� �������� ���� ���� �ڵ� �Է��ϸ� ��
		}
		//2�� ������ �� ���� Ȯ��
		if (UserOrder == 2) {
			system("cls");
			printf("==================================================\n\n");
			printf("              ��                ��                 \n\n\n");
		}
		//3�� ������ �� ���� ����
		if (UserOrder == 3) {
			system("cls");
			printf("������ �����մϴ�.\n");
			exit(1);
		}
	}
}
