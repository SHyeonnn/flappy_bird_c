#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define Map_High 0
#define Map_Distance 24

void gotoXY(int x, int y); // X좌표와 Y좌표 조정하기
void Map1(int Map_Position1); // 첫번째 장애물 모양 그리기
void Map2(int Map_Position2); // 두번째 장애물 모양 그리기
void Map3(int Map_Position3); // 세번째 장애물 모양 그리기

void Console()
{
    system("mode con cols=50 lines=50");
}

int main(void)
{
    Console();

    int MapX2_Flag = 0; // 두번째 장애물이 나오는 주기 설정
    int MapX3_Flag = 0; // 세번째 장애물이 나오는 주기 설정
    int MapX1 = Map_Distance; //첫번째 장애물의 거리를 50으로 지정
    int MapX2 = Map_Distance; // 두번째 장애물의 거리를 50으로 지정
    int MapX3 = Map_Distance; // 세번째 장애물의 거리를 50으로 지정


    while (true)
    {
        MapX1 -= 2; // 1번째 장애물를 움직이는 변수

        if (MapX1 <= 1)
            MapX1 = Map_Distance; // 1번째 장애물의 x좌표가 1보다 작아진다면 장애물의 위치 초기화
        if (MapX1 == 16)
            MapX2_Flag += 1;; // 1번째 장애물의 위치가 중간에 왔다면 2번째 장애물 출력을 위한 변수 초기화
        if (MapX1 == 8)
            MapX3_Flag += 1;
        if (MapX2_Flag == 1){
            Map2(MapX2);
            MapX2 -= 2;
        }
        if (MapX2 <= 1){
            MapX2 = Map_Distance; // 2번째 장애물의 x좌표가 1보다 작아진다면 위치 초기화
            MapX2_Flag = 0;
        }
        if (MapX3_Flag == 1) {
            Map3(MapX3);
            MapX3 -= 2;
        }
        if (MapX3 <= 1){
            MapX3 = Map_Distance; // 3번째 장애물의 x좌표가 1보다 작아진다면 위치 초기화
            MapX3_Flag = 0;
        }

        Map1(MapX1);

        Sleep(200);
        system("cls");
    }
}

void gotoXY(int x, int y) // 사물의 x좌표와 y좌표를 나타내는 함수
{
    COORD pos;
    pos.X = 2*x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Map1(int Map_Position1) //첫번째 장애물
{
    int i = 0;
    while (i < 50) {
        gotoXY(Map_Position1, Map_High + i);
        if (i >= 11 && i <= 28)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}
void Map2(int Map_Position2) // 두번째 장애물
{
    int i = 0;
    while (i < 50) {
        gotoXY(Map_Position2, Map_High + i);
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
        gotoXY(Map_Position3, Map_High + i);
        if (i >= 22 && i <= 38)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}