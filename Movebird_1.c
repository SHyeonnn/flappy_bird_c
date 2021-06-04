/*��ֹ��� ����� ������ ������ �ö󰡴� �Լ�*/
#include <stdio.h>
#include<stdbool.h>
#include <conio.h>
#include <windows.h>
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
    printf("         \n");
}
void MoveBird() //���� �ߴµ� z ������ �� ������� bool ��Ÿ� ���ظ� ���� ���ؼ�,,,
{
    bool UP = false;
    bool DOWN = true;
    const int gravity = 1;

    int bird = bird_head;

    while (true)
    {

        if (GetKeyDown() == 'z')
        {
            UP = true;
            DOWN = false;
        }
            bird += gravity;
            if (UP)
            {
                bird -= gravity;
            }
            else
            {
                bird += gravity;
            }

        DrawBird(bird);
        Sleep(60);  //���� �ӵ� ����
        system("cls");    //â Ŭ���� ���߿� ����� ����
    }
    system("pause");
}
int main(void)
{
    Console();
    MoveBird();
}