#include <stdio.h> //movebird������Ʈ
#include<stdbool.h>
#include <conio.h>
#include <windows.h>
#include<time.h>
#define bird_head 18

void Console()
{
    system("mode con:cols=50 lines=50");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void DrawBird(int bird)
{
    GotoXY(0, bird);
    printf("      ***         \n ");
    printf("   *   O *           \n ");
    printf("   *     *     \n");
    printf("      ***        \n");
    printf("      L L    \n");
}

int main(void)
{
    Console();

    int UserOrder = 0;
    int StartOrder = 0;
    int End = 0;
    int score = 0;

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
            system("cls");

            //���� ���� �ڵ�
            bool UP = false;
            bool DOWN = true;
            const int gravity = 2;

            int bird = bird_head;

            int End = 0;    //���� ���Ḧ ���� ���� �ʱ�ȭ
            int score = 0;   //���� ī��Ʈ ���� �ʱ�ȭ
            clock_t start, curr;    //���� ���� �ʱ�ȭ
            start = clock();


            while (true)
            {
                //z�� ������ ���� ���� �� ������ �Ʒ���
                if (GetKeyDown() == 'z')
                {
                    UP = true;
                    DOWN = false;
                }
                if (UP) {
                    bird -= gravity * 2;
                    UP = false;
                    DOWN = true;
                }
                else {
                    bird += gravity;
                }

                //õ��, �ٴ� ��ġ�� ������ ���� ����
                if (bird <= 2)
                {
                    if (bird == 2)
                    {
                        End++;
                        system("cls");
                    }

                }
                if (bird >= 46)
                {
                    if (bird == 46)
                    {
                        End++;
                        system("cls");
                    }
                }

                DrawBird(bird); //�� �׸���

                curr = clock();   //���� �ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)  // 1�ʰ� �Ѿ��� ��
                {
                    score++;    //���ھ� UP
                    start = clock();    //���� �ð� �ʱ�ȭ
                }

                Sleep(60);
                system("cls");
            }
        }system("pause");
    }
    //���� ���� ȭ��
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
        printf("                     SCORE : %d                   \n\n", score);

        Sleep(100);
    }
}