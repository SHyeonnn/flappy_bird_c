#include <stdio.h>                   //flappy_bird ������Ʈ
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#pragma warning (disable : 4996)


#define bird_head 18
#define Map_High 0
#define Map_Distance 25

void Map1(int Map_Position1); // ù��° ��ֹ� ��� �׸���
void Map2(int Map_Position2); // �ι�° ��ֹ� ��� �׸���
void Map3(int Map_Position3); // ����° ��ֹ� ��� �׸���

void endrank(int endinput);

void Console() {  //�ܼ�â�� ũ�⸦ �����ϴ� �Լ�
    system("mode con:cols=50 lines=50");
}

void GotoXY(int x, int y) {  //Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {  //Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void DrawBird(int bird_x, int bird_y) { //�� ĳ���͸� ��½�ų �Լ�
    GotoXY(bird_x, bird_y);
    printf("        ***      \n ");
    printf("     *   O *     \n ");
    printf("     *     *     \n");
    printf("        ***      \n");
    printf("        L L      \n");
}
void ShowScore(int score) {  //�ΰ��ӿ� ������ ��Ÿ���� �Լ�
    GotoXY(20, 0);
    printf("SCORE : %d", score);
}
int main() {
    Console();
    int UserOrder = 0;  //������� �޴��� ������ ���� ����
    int End = 0;        //������ ����� ������ �����Ǿ��� �� +1�� �Ͽ� ������ �����ų �� �ִ� ����
    int score = 0;      //������ ����� ����
    int MapX1 = Map_Distance; //ù��° ��ֹ��� �Ÿ��� 24�� ����
    int MapX2 = Map_Distance; // �ι�° ��ֹ��� �Ÿ��� 24�� ����
    int MapX3 = Map_Distance; // ����° ��ֹ��� �Ÿ��� 24�� ����
    int MapX2_Flag = 0; // �ι�° ��ֹ��� ������ �ֱ� ����
    int MapX3_Flag = 0; // ����° ��ֹ��� ������ �ֱ� ����
    int Endinput = 0;

    if (End == 0) {     //���� ȭ�� ���
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

        if (UserOrder == 2) {  //2�� ������ �� "����" Ȯ��
            system("cls");
            char line[255];
            int count = 1;
            FILE* file_pt;
            fopen_s(&file_pt, "rank.txt", "a+");
            printf("==================================================\n\n");
            printf("              ��                ��                \n\n\n");
            while (fgets(line, sizeof(line), file_pt) != NULL) {
                printf("\t\t%d�� \t%s\n\n", count, line);
                count++;
            }
        }
        if (UserOrder == 3) {  //3�� ������ �� "���� ���" Ȯ��
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
        if (UserOrder == 4) {  //4�� ������ �� "���� ����"
            system("cls");
            printf("\n\n\n\n\n                ������ �����մϴ�.           \n\n\n\n");
            exit(1);
            system("cls");
        }
        if (UserOrder == 1) {  //����ڰ� 1�� ������ �� ���� ����
            printf("��  ��  ��....");
            Sleep(1000);
            system("cls");

            bool UP = false;      //���� ���� �ڵ�
            bool DOWN = true;
            const int gravity = 2;

            int bird[2] = { 0, bird_head };

            clock_t start, curr;  //���� ���� �ʱ�ȭ
            start = clock();

            while (true) {  //z�� ������ ���� ���� �� ������ �Ʒ���
                void ShowScore(score);
                if (GetKeyDown() == 'z') {
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

                if (bird[1] <= 1 || bird[1] >= 44) {  //õ��, �ٴ� ��ġ�� ������ ���� ����
                    End = 1;
                    system("cls");
                    break;
                }
                MapX1 -= 2; // 1��° ��ֹ��� �����̴� ����
                if (MapX1 <= 1) {
                    MapX1 = Map_Distance; //ù ��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ֹ��� ��ġ �ʱ�ȭ
                }
                if (MapX1 == 13) {
                    MapX2_Flag += 1; //ù ��° ��ֹ��� ��ġ�� �߰��� �Դٸ� �� ��° ��ֹ� ����� ���� ���� �ʱ�ȭ
                }
                if (MapX1 == 8) {
                    MapX3_Flag += 1;
                }
                if (MapX2_Flag == 1) {
                    Map2(MapX2);
                    MapX2 -= 2;
                }
                if (MapX2 <= 1) {
                    MapX2 = Map_Distance; //�� ��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ġ �ʱ�ȭ
                    MapX2_Flag = 0;
                }
                if (MapX3_Flag == 1) {
                    Map3(MapX3);
                    MapX3 -= 2;
                }
                if (MapX3 <= 1) {
                    MapX3 = Map_Distance; //�� ��° ��ֹ��� x��ǥ�� 1���� �۾����ٸ� ��ġ �ʱ�ȭ
                    MapX3_Flag = 0;
                }
                if (MapX1 >= 2 && MapX1 <= 6) {  // ù ��° ��ֹ��� ������ ���� ����
                    if ((bird[1] >= 0 && bird[1] <= 11) || (bird[1] >= 25 && bird[1] < 50)) {
                        End = 1;
                        system("cls");
                        break;
                    }
                }
                if (MapX2 >= 2 && MapX2 <= 6) {  // �� ��° ��ֹ��� ������ ���� ����
                    if ((bird[1] >= 0 && bird[1] <= 19) || (bird[1] >= 30 && bird[1] < 50)) {
                        End = 1;
                        system("cls");
                        break;
                    }
                }
                if (MapX3 >= 2 && MapX3 <= 6) {  // �� ��° ��ֹ��� ������ ���� ����
                    if ((bird[1] >= 0 && bird[1] <= 22) || (bird[1] >= 35 && bird[1] < 50)) {
                        End = 1;
                        system("cls");
                        break;
                    }
                }
                Map1(MapX1);
                ShowScore(score);
                DrawBird(bird[0], bird[1]); //�� �׸���

                curr = clock();   //���� �ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)  // 1�ʰ� �Ѿ��� ��
                {
                    score++;           //���ھ� UP
                    start = clock();   //���� �ð� �ʱ�ȭ
                }
                ShowScore(score);
                Sleep(80);
                system("cls");
            }
        }
    }
    if (End == 1) {  //���� ���� ȭ��
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

        printf("          1. ���� ���   2. ���� ����            \n\n");
        printf("                    -->  ");
        scanf_s("%d", &Endinput);
        if (Endinput == 1) {
            endrank(score);
        }
        Sleep(100);
    }
}
void endrank(int score) {
    system("cls");
    char name[6] = { 0 };
    char rank[3][255] = { 0 };
    char rank_score[3][255] = { 0 };
    int count = 0;
    char* temp_1 = "";
    char temp_2[255] = { 0 };
    char line[255];

    FILE* file_pt;
    fopen_s(&file_pt, "rank.txt", "a+");
    while (fgets(line, sizeof(line), file_pt) != NULL) {
        if (line[0] != ' ') {
            printf("%s", line);
            strcpy(temp_2, line);

            temp_1 = strtok(temp_2, " ");
            strcpy(rank[count], temp_1);

            temp_1 = strtok(NULL, " ");
            strcpy(rank_score[count], temp_1);

            for (int i = 0; rank_score[count][i] != 0; i++) {
                // �ٹٲ� ���ڸ� ���� ���!
                if (rank_score[count][i] == '\n') {
                    rank_score[count][i] = 0;  // �ٹٲ� ���ڰ� �ִ� ��ġ�� NULL ���ڸ� �����Ѵ�!
                    break;        // �ݺ��� �ߴ��Ѵ�!
                }
            }

            count++;
        }


    }



    printf("                                                  \n");
    printf("==================================================\n\n");
    printf("                                                  \n");
    printf("                                                  \n");
    printf("                   SCORE : %d                     \n\n", score);
    printf("                                                  \n");
    printf("          Ranking �̴ϼ��� �Է��ϼ���            \n\n");
    printf("                 * 5���� ����                    \n\n");
    printf("                                                  \n");
    printf("                    -->  ");
    scanf("%s", name);

    for (int i = 0; i < 3; i++) {
        if (score >= atoi(rank_score[i])) {
            for (int j = 1; j >= i; j--) {
                strcpy(rank_score[j + 1], rank_score[j]);
                strcpy(rank[j + 1], rank[j]);
            }
            strcpy(rank[i], name);
            itoa(score, rank_score[i], 10);
            break;
        }
    }
    fclose(file_pt);
    fopen_s(&file_pt, "rank.txt", "w+");

    for (int i = 0; i < 3; i++) {
        fprintf(file_pt, "%s %s\n", rank[i], rank_score[i]);
    }
    fclose(file_pt);



}
void Map1(int Map_Position1) //ù ��° ��ֹ�
{
    int i = 0;
    while (i < 50) {
        GotoXY(Map_Position1, Map_High + i);
        if (i >= 11 && i <= 28)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}
void Map2(int Map_Position2) // �� ��° ��ֹ�
{
    int i = 0;
    while (i < 50) {
        GotoXY(Map_Position2, Map_High + i);
        if (i >= 19 && i <= 33)
            printf("   \n");
        else
            printf("***\n");
        i++;
    }
}

void Map3(int Map_Position3) // �� ��° ��ֹ�
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