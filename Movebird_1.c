/*장애물을 통과할 때마다 점수가 올라가는 함수*/
#include <stdio.h>
#include<stdbool.h>
#include <conio.h>
#include <windows.h>
#define bird_head 18

void Console()
{
    system("mode con:cols=50 lines=50");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
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
void MoveBird() //나름 했는데 z 누르면 걍 멈춰버림 bool 요거를 이해를 아직 못해서,,,
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
        Sleep(60);  //점프 속도 조절
        system("cls");    //창 클리어 나중에 써먹을 예정
    }
    system("pause");
}
int main(void)
{
    Console();
    MoveBird();
}