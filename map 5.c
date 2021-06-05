#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define Map_High 0
#define Map_Distance 24

void gotoXY(int x, int y); // X��ǥ�� Y��ǥ �����ϱ�
void Map1(int Map_Position1); // ù��° ��ֹ� ��� �׸���
void Map2(int Map_Position2); // �ι�° ��ֹ� ��� �׸���
void Map3(int Map_Position3); // ����° ��ֹ� ��� �׸���

void Console()
{
    system("mode con cols=50 lines=50");
}

int main(void)
{
    Console();

    int MapX2_Flag = 0; // �ι�° ��ֹ��� ������ �ֱ� ����
    int MapX3_Flag = 0; // ����° ��ֹ��� ������ �ֱ� ����
    int MapX1 = Map_Distance; //ù��° ��ֹ��� �Ÿ��� 50���� ����
    int MapX2 = Map_Distance; // �ι�° ��ֹ��� �Ÿ��� 50���� ����
    int MapX3 = Map_Distance; // ����° ��ֹ��� �Ÿ��� 50���� ����


    while (true)
    {
        MapX1 -= 2; // 1��° ��ֹ��� �����̴� ����

        if (MapX1 <= 1)
            MapX1 = Map_Distance; // 1��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ֹ��� ��ġ �ʱ�ȭ
        if (MapX1 == 16)
            MapX2_Flag += 1;; // 1��° ��ֹ��� ��ġ�� �߰��� �Դٸ� 2��° ��ֹ� ����� ���� ���� �ʱ�ȭ
        if (MapX1 == 8)
            MapX3_Flag += 1;
        if (MapX2_Flag == 1){
            Map2(MapX2);
            MapX2 -= 2;
        }
        if (MapX2 <= 1){
            MapX2 = Map_Distance; // 2��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ġ �ʱ�ȭ
            MapX2_Flag = 0;
        }
        if (MapX3_Flag == 1) {
            Map3(MapX3);
            MapX3 -= 2;
        }
        if (MapX3 <= 1){
            MapX3 = Map_Distance; // 3��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ġ �ʱ�ȭ
            MapX3_Flag = 0;
        }

        Map1(MapX1);

        Sleep(200);
        system("cls");
    }
}

void gotoXY(int x, int y) // �繰�� x��ǥ�� y��ǥ�� ��Ÿ���� �Լ�
{
    COORD pos;
    pos.X = 2*x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Map1(int Map_Position1) //ù��° ��ֹ�
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
void Map2(int Map_Position2) // �ι�° ��ֹ�
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

void Map3(int Map_Position3) // ����° ��ֹ�
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