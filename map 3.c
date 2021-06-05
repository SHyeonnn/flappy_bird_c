#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define High 0
#define Distance 50

void gotoXY(int x, int y); // X��ǥ�� Y��ǥ �����ϱ�
void Map1(int TreePosition1); // ù��° ��ֹ� ��� �׸���
void Map2(int TreePosition2); // �ι�° ��ֹ� ��� �׸���

void Console()
{
    system("mode con cols=50 lines=50");
}

int main(void)
{
    Console();

    int MapX2_Flag = 0; // �ι�° ��ֹ��� ������ �ֱ� ����
    int MapX1 = Distance; //ù��° ��ֹ��� �Ÿ��� 50���� ����
    int MapX2 = Distance; // �ι�° ��ֹ��� �Ÿ��� 50���� ����

   
        while (true)
        {
            MapX1 -= 2; // 1��° ��ֹ��� �����̴� ����

            if (MapX1 <= 1)
            {
                MapX1 = Distance; // 1��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ֹ��� ��ġ �ʱ�ȭ
            }

            if (MapX1 == 24)
            {
                MapX2_Flag += 1;; // 1��° Ʈ���� ��ġ�� �߰��� �Դٸ� 2��° ��ֹ� ����� ���� ���� �ʱ�ȭ
            }

            if (MapX2_Flag == 1)
            {
                Map2(MapX2);
                MapX2 -= 2;
            }

            if (MapX2 <= 1)
            {
                MapX2 = Distance; // 2��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ġ �ʱ�ȭ
                MapX2_Flag = 0;
            }


       
            Map1(MapX1);

            Sleep(100);
            system("cls");
        }
}

void gotoXY(int x, int y) // �繰�� x��ǥ�� y��ǥ�� ��Ÿ���� �Լ�
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Map1(int Map_Position1) //ù��° ��ֹ�
{
    int i = 0;
    while (i<50) {
        gotoXY(Map_Position1, High + i);
        if (i >= 22 && i <= 34)
            printf("   \n");
        else 
            printf("@@@\n");
        i++;
    }
}
void Map2(int Map_Position2) // �ι�° ��ֹ�
{
    int i = 0;
    while (i < 50) {
        gotoXY(Map_Position2, High + i);
        if (i >= 32 && i <= 43)
            printf("   \n");
        else
            printf("@@@\n");
        i++;
    }
}