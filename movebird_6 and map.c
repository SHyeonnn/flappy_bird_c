#include <stdio.h> 
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define bird_head 18
#define Map_High 0
#define Map_Distance 22 //�� ������ ����

void Console() { //�ܼ�â ũ�� ���� �Լ�
    system("mode con:cols=50 lines=50");
}

void GotoXY(int x, int y) { //Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {  //Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
    if (_kbhit() != 0){
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

void ShowScore(int score){
    GotoXY(20, 0);
    printf("SCORE : %d", score);
}

void Map1(int Map_Position1) {          //ù ��° ��ֹ�
    int i = 0;
    GotoXY(Map_Position1, Map_High + i);
    while (i < 50) {
        GotoXY(Map_Position1, Map_High + i);
        if (i >= 10 && i <= 20)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}
void Map2(int Map_Position2) {         //�� ��° ��ֹ�
    int i = 0;
    GotoXY(Map_Position2, Map_High + i);
    while (i < 50) {
        GotoXY(Map_Position2, Map_High + i);
        if (i >= 32 && i <= 43)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}

int main() {
    Console();
    void Map1(Map_Position1); // ù��° ��ֹ� ��� �׸���
    void Map2(TreePosition2); // �ι�° ��ֹ� ��� �׸���
    int MapX1 = Map_Distance; //ù ��° ��ֹ��� �Ÿ��� 50���� ����
    int MapX2 = Map_Distance; //�� ��° ��ֹ��� �Ÿ��� 50���� ����
    int MapX2_Flag = 0;   //�� ��° ��ֹ��� ������ �ֱ� ����
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
        printf("          1. ���� ����   2. ���� Ȯ��            \n\n");
        printf("          3. ���� ���   4. ���� ����            \n\n");
        printf("                    -->  ");
        scanf_s("%d", &UserOrder);

        //2�� ������ �� ���� Ȯ��
        if (UserOrder == 2) {
            system("cls");
            printf("==================================================\n\n");
            printf("              ��                ��                \n\n\n");
        }
        //3�� ������ �� ���� ��� Ȯ��
        if (UserOrder == 3) {
            system("cls");
            printf("==================================================\n\n");
            printf("                ��   ��   ��   ��                 \n\n");
            printf("  1. ���� ��ֹ��� �浹�ϰų�,                    \n");
            printf("     õ�� �Ǵ� �ٴڿ� ����� �� ������ ����˴ϴ� \n\n");
            printf("  2. 'z'Ű�� ������ ���� ��Ʈ�� �Ͽ�              \n");
            printf("     ��ֹ��� ���� �� �ֽ��ϴ�                    \n\n");
            printf("  3. �ð��� ���� ���� �ӵ��� �������ϴ�           \n\n");
            printf("==================================================\n\n");
        }
        //4�� ������ �� ���� ����
        if (UserOrder == 4) {
            system("cls");
            printf("\n\n\n\n\n                ������ �����մϴ�.           \n\n\n\n");
            exit(1);
            system("cls");
        }
        //����ڰ� 1�� ������ �� ���� ����
        if (UserOrder == 1) {
            printf("��  ��  ��....");
            Sleep(1000);
            system("cls");

            bool UP = false;
            bool DOWN = true;
            const int gravity = 2;

            int bird[2] = { 0, bird_head };
            clock_t start, curr;                //���� ���� �ʱ�ȭ
            start = clock();

            ShowScore(score);
            while (true) {                //���� ���� �ڵ�
               
                if (GetKeyDown() == 'z')  //z�� ������ ���� ���� �� ������ �Ʒ���
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
                if (bird[1] <= 2 || bird[1] >= 46) {  //õ��, �ٴ� ��ġ�� ������ ���� ����
                    End = 1;
                    system("cls");
                    break;
                }
                MapX1 -= 2; // 1��° ��ֹ��� �����̴� ����
                if (MapX1 <= 1) { //�̰� ���� 1�̾��µ� ���� �ٲ� �ٵ� �ǹ� ���� �� ���� �ٵ� �ٲ㼭 �׷���
                    MapX1 = Map_Distance; // 1��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ֹ��� ��ġ �ʱ�ȭ
                }
                if (MapX1 == 24) {
                    MapX2_Flag += 1; // 1��° Ʈ���� ��ġ�� �߰��� �Դٸ� 2��° ��ֹ� ����� ���� ���� �ʱ�ȭ
                }
                if (MapX2_Flag == 1) {
                    //Map2(MapX2);
                    MapX2 -= 2;
                }
                if (MapX2 <= 3) {
                    MapX2 = Map_Distance; // 2��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ġ �ʱ�ȭ
                    MapX2_Flag = 0;
                }

                Map1(MapX1);
                Map2(MapX2);

                DrawBird(0, bird[1]);         //�� �׸���
                Sleep(50);

                curr = clock();                                   //���� �ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1) {     // 1�ʰ� �Ѿ��� ��
                    score++;                                      //���ھ� UP -> 1�ʿ� 1���� ����
                    start = clock();                              //���� �ð� �ʱ�ȭ
                }
                Sleep(100);
                system("cls");
            }
        }
    }
    if (End == 1) {         //���� ���� ȭ��
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