#include <stdio.h> 
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
//수정해서 push해야 하는 코드

#define bird_head 18
#define Map_High 0
#define Map_Distance 24 //맵 사이의 간격

void Console() { //콘솔창 크기 조절 함수
    system("mode con:cols=50 lines=50");
}

void GotoXY(int x, int y) { //커서의 위치를 x, y로 이동하는 함수
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {  //키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void DrawBird(int bird_x, int bird_y) {  //새 그리는 함수
    GotoXY(bird_x, bird_y);
    printf("      ***      \n ");
    printf("   *   O *     \n ");
    printf("   *     *     \n");
    printf("      ***      \n");
    printf("      L L      \n");
}

void ShowScore(int score)  //게임 내에서 점수를 보여주는 함수
{
    GotoXY(19, 0);
    printf("SCORE : %d", score);
}

void Map1(int Map_Position1) {          //첫 번째 장애물
    int i = 0;
    GotoXY(Map_Position1, Map_High + i);
    while (i < 50) {
        GotoXY(Map_Position1, Map_High + i);
        if (i >= 11 && i <= 28)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}
void Map2(int Map_Position2) {         //두 번째 장애물
    int i = 0;
    GotoXY(Map_Position2, Map_High + i);
    while (i < 50) {
        GotoXY(Map_Position2, Map_High + i);
        if (i >= 19 && i <= 33)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}
void Map3(int Map_Position3) // 세번째 장애물
{
    int i = 0;
    while (i < 50) {
        GotoXY(Map_Position3, Map_High + i);
        if (i >= 22 && i <= 38)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}

int main() {
    Console();
    void Map1(Map_Position1); // 첫 번째 장애물 모양 그리기
    void Map2(Map_Position2); // 두 번째 장애물 모양 그리기
    void Map3(Map_Position3); // 세 번째 장애물 모양 그리기
    int MapX1 = Map_Distance; //첫 번째 장애물의 거리를 20으로 지정
    int MapX2 = Map_Distance; //두 번째 장애물의 거리를 20으로 지정
    int MapX3 = Map_Distance; //세 번째 장애물의 거리를 20으로 지정
    int MapX2_Flag = 0;   //두 번째 장애물이 나오는 주기 설정
    int MapX3_Flag = 0;   //세 번째 장애물이 나오는 주기 설정
    int UserOrder = 0;
    int End = 0;
    int score = 0;
    int i = 0;

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
            printf("  2. 'z'키를 누르며 새를 컨트롤 하여              \n");
            printf("     장애물을 피할 수 있습니다                    \n\n");
            printf("  3. 시간에 따라 맵의 속도가 빨라집니다           \n\n");
            printf("==================================================\n\n");
        }
        //4를 눌렀을 때 게임 종료
        if (UserOrder == 4) {
            system("cls");
            printf("\n\n\n\n\n                게임을 종료합니다.           \n\n\n\n");
            exit(1);
            system("cls");
        }
        //사용자가 1을 눌렀을 때 게임 시작
        if (UserOrder == 1) {
            printf("로  딩  중....");
            Sleep(1000);
            system("cls");

            bool UP = false;
            bool DOWN = true;
            const int gravity = 2;

            int bird[2] = { 0, bird_head };
            clock_t start, curr;                //점수 변수 초기화
            start = clock();


            while (true) {                //게임 진행 코드
                ShowScore(score);
                if (GetKeyDown() == 'z')  //z를 누르면 새가 위로 안 누르면 아래로
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
                if (bird[1] <= 2 || bird[1] >= 43) {  //천장, 바닥 위치에 닿으면 게임 종료
                    End = 1;
                    system("cls");
                    break;
                }
                if (MapX1 <= 2 && MapX1 <= 5) {  //첫 번째 장애물에 닿으면 게임 종료
                    if ((bird[1] >= 0 && bird[1] <= 11) || (bird[1] >= 25 && bird[1] < 50)) {
                        End = 1;
                        system("cls");
                        break;
                    }
                }
                if (MapX2 <= 2 && MapX2 <= 5) {  //두 번째 장애물에 닿으면 게임 종료
                    if ((bird[1] >= 0 && bird[1] <= 19) || (bird[1] >= 30 && bird[1] < 50)) {
                        End = 1;
                        system("cls");
                        break;
                    }
                }
                if (MapX3 <= 2 && MapX3 <= 5) {  //세 번째 장애물에 닿으면 게임 종료
                    if ((bird[1] >= 0 && bird[1] <= 22) || (bird[1] >= 35 && bird[1] < 50)) {
                        End = 1;
                        system("cls");
                        break;
                    }
                }
                MapX1 -= 2; // 1번째 장애물를 움직이는 변수
                if (MapX1 <= 1)
                    MapX1 = Map_Distance; // 1번째 장애물의 x좌표가 1보다 작아진다면 장애물의 위치 초기화
                if (MapX1 == 16)
                    MapX2_Flag += 1;; // 1번째 장애물의 위치가 중간에 왔다면 2번째 장애물 출력을 위한 변수 초기화
                if (MapX1 == 8)
                    MapX3_Flag += 1;
                if (MapX2_Flag == 1) {
                    Map2(MapX2);
                    MapX2 -= 2;
                }
                if (MapX2 <= 1) {
                    MapX2 = Map_Distance; // 2번째 장애물의 x좌표가 1보다 작아진다면 위치 초기화
                    MapX2_Flag = 0;
                }
                if (MapX3_Flag == 1) {
                    Map3(MapX3);
                    MapX3 -= 2;
                }
                if (MapX3 <= 1) {
                    MapX3 = Map_Distance; // 3번째 장애물의 x좌표가 1보다 작아진다면 위치 초기화
                    MapX3_Flag = 0;
                }
                Map1(MapX1);
                DrawBird(bird[0], bird[1]);         //새 그리기

                curr = clock();                                   //현재 시간 받아오기
                if (((curr - start) / CLOCKS_PER_SEC) >= 1) {     // 1초가 넘었을 때
                    score++;                                      //스코어 UP -> 1초에 1점씩 증가
                    start = clock();                              //시작 시간 초기화
                }
                system("cls");
                Sleep(60);
            }
        }
    }
    if (End == 1) {         //게임 종료 화면
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