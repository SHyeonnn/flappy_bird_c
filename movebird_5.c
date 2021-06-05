#include <stdio.h> 
#include<stdbool.h>
#include <conio.h>
#include <windows.h>
#include<time.h>
#define bird_head 18


void Console() {
    system("mode con:cols=50 lines=50");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown() {
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void DrawBird(int bird_x, int bird_y) {
    GotoXY(bird_x, bird_y);
    printf("      ***      \n ");
    printf("   *   O *     \n ");
    printf("   *     *     \n");
    printf("      ***      \n");
    printf("      L L      \n");
}

void Showscore(int score)
{
    GotoXY(20, 0);
    printf("SCORE : %d", score);
}

int main() {
    Console();

    int UserOrder = 0;
    int End = 0;
    int score = 0;


    if (End == 0) {
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
        printf("          1. 게임 시작   2. 순위 확인            \n\n");
        printf("          3. 게임 방법   4. 게임 종료            \n\n");
        printf("                    -->  ");
        scanf_s("%d", &UserOrder);

        //2를 눌렀을 때 순위 확인
        if (UserOrder == 2) {
            system("cls");
            printf("==================================================\n\n");
            printf("              순                위                \n\n\n");
        }
        //3을 눌렀을 때 게임 방법 확인
        if (UserOrder == 3) {
            system("cls");
            printf("==================================================\n\n");
            printf("                게   임   방   법                 \n\n");
            printf("  1. 새가 장애물에 충돌하거나,                    \n");
            printf("     천장 또는 바닥에 닿았을 때 게임이 종료됩니다 \n\n");
            printf("  2. 'z'키를 누르면 새가 위로 날아가고,           \n\n");
            printf("       \n\n");
            printf("  1.  \n\n");
        }

        //4를 눌렀을 때 게임 종료
        if (UserOrder == 4) {
            system("cls");
            printf("\n\n\n\n\n               게임을 종료합니다.            \n\n\n\n");
            exit(1);
            system("cls");
        }
        //사용자가 1을 눌렀을 때 게임 시작
        if (UserOrder == 1) {
            printf("로  딩  중....");
            Sleep(1000);
            system("cls");

            //게임 진행 코드
            bool UP = false;
            bool DOWN = true;
            const int gravity = 2;

            int bird[2] = { 0,bird_head };

            clock_t start, curr;    //점수 변수 초기화
            start = clock();


            while (true)
            {
                //z를 누르면 새가 위로 안 누르면 아래로
                if (GetKeyDown() == 'z')
                {
                    UP = true;
                    DOWN = false;
                }
                if (UP) {
                    bird[1] -= gravity * 2;
                    UP = false;
                    DOWN = true;
                }
                else {
                    bird[1] += gravity;
                }

                //천장, 바닥 위치에 닿으면 게임 종료
                if (bird[1] <= 2 || bird[1] >= 43)
                {
                    End = 1;
                    system("cls");
                    break;
                }

                DrawBird(bird[0], bird[1]); //새 그리기

                curr = clock();   //현재 시간 받아오기
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)  // 1초가 넘었을 때
                {
                    score++;    //스코어 UP -> 1초에 1점씩 증가
                    start = clock();    //시작 시간 초기화
                }
                Showscore(score);

                Sleep(60);
                system("cls");
            }
        }
    }
    //게임 종료 화면
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
        printf("                   SCORE : %d                     \n\n", score);

        Sleep(100);
    }
}