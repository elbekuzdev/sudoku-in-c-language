#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char box[9][9] = {
    {'5', ' ', ' ', /**/ ' ', '6', '2', /**/ ' ', ' ', ' '},
    {'3', ' ', ' ', /**/ ' ', ' ', ' ', /**/ '1', '2', '5'},
    {'7', '2', ' ', /**/ ' ', ' ', ' ', /**/ ' ', ' ', '3'},
    /////////////////////////////////////////////////////
    {' ', ' ', ' ', /**/ ' ', '1', ' ', /**/ '3', ' ', ' '},
    {'2', ' ', ' ', /**/ '4', ' ', '8', /**/ ' ', ' ', ' '},
    {'8', '1', ' ', /**/ '6', ' ', ' ', /**/ ' ', ' ', ' '},
    /////////////////////////////////////////////////////
    {' ', ' ', ' ', /**/ '2', '8', ' ', /**/ ' ', ' ', ' '},
    {' ', ' ', ' ', /**/ '9', '3', '6', /**/ '7', ' ', ' '},
    {' ', ' ', '3', /**/ ' ', ' ', '1', /**/ ' ', '9', '4'}

};

char checkbox[9][9] = {
    {'5', '9', '1', '3', '6', '2', '8', '4', '7'},
    {'3', '6', '4', '8', '9', '7', '1', '2', '5'},
    {'7', '2', '8', '1', '4', '5', '9', '6', '3'},
    {'4', '7', '6', '5', '1', '9', '3', '8', '2'},
    {'2', '3', '9', '4', '7', '8', '5', '1', '6'},
    {'8', '1', '5', '6', '2', '3', '4', '7', '9'},
    {'9', '5', '7', '2', '8', '4', '6', '3', '1'},
    {'1', '4', '2', '9', '3', '6', '7', '5', '8'},
    {'6', '8', '3', '7', '5', '1', '2', '9', '4'},
};

char qator, ustun, tanla;
int countr = 0;

void show_table();
void input();
void input_check();
void freespace();
void tanlamoq();
void togrilikka_check();
bool boshkatak();


int main()
{
    system("cls");

    while (boshkatak())
    {
        if (countr == 0)
        printf("\t\t\tAssalomu alaykum,\n\t\tSudoku o'yiniga xush kelibsiz\n");
        show_table();

        countr++;
        input();
        input_check();
        freespace();
        box[qator][ustun] = 'X';
        show_table();
        tanlamoq();
        togrilikka_check();
    }
    system("COLOR 0E");
    show_table();
    printf("\n\t\t\tTABRIKLAYMIZ YUTDINGIZ !!!");
    getch();
    return 0;
}

void show_table()
{
    if (countr != 0)
    system("cls");

    printf(" _______________________________________________________________________\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[0][0], box[0][1], box[0][2], box[0][3], box[0][4], box[0][5], box[0][6], box[0][7], box[0][8]);
    printf("| _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ |\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[1][0], box[1][1], box[1][2], box[1][3], box[1][4], box[1][5], box[1][6], box[1][7], box[1][8]);
    printf("| _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ |\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[2][0], box[2][1], box[2][2], box[2][3], box[2][4], box[2][5], box[2][6], box[2][7], box[2][8]);
    printf("|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[3][0], box[3][1], box[3][2], box[3][3], box[3][4], box[3][5], box[3][6], box[3][7], box[3][8]);
    printf("| _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ |\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[4][0], box[4][1], box[4][2], box[4][3], box[4][4], box[4][5], box[4][6], box[4][7], box[4][8]);
    printf("| _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ |\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[5][0], box[5][1], box[5][2], box[5][3], box[5][4], box[5][5], box[5][6], box[5][7], box[5][8]);
    printf("|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[6][0], box[6][1], box[6][2], box[6][3], box[6][4], box[6][5], box[6][6], box[6][7], box[6][8]);
    printf("| _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ |\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[7][0], box[7][1], box[7][2], box[7][3], box[7][4], box[7][5], box[7][6], box[7][7], box[7][8]);
    printf("| _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ | _ _ _ |\n");
    printf("|       |       |       |       |       |       |       |       |       |\n");
    printf("|   %c       %c       %c   |   %c       %c       %c   |   %c       %c       %c   |\n", box[8][0], box[8][1], box[8][2], box[8][3], box[8][4], box[8][5], box[8][6], box[8][7], box[8][8]);
    printf("|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
}

void input()
{
    printf("\nQatorni kiriting[1/9]: ");
    scanf(" %c", &qator);
    qator -= '1';
    printf("Ustunni kiriting[1/9]: ");
    scanf(" %c", &ustun);
    ustun -= '1';
}

void input_check()
{
    while (qator <= '1' && qator >= '9' && ustun <= '1' && ustun >= '9')
    {
        printf("\n[1/9] oraliqda kiritng\n");
        input();
    }
    while (tanla <= '1' && tanla >= '9')
    {
        printf("\n[1/9] oraliqda kiritng\n");
        tanlamoq();
    }
}

void freespace()
{
    while (box[qator][ustun] != ' ')
    {
        printf("\nBo'sh katakka kiriting\n");
        input();
    }
}

void tanlamoq()
{
    printf("\nTanlagan katakingizga nechchi raqam qo'ymoqchisiz: ");
    scanf(" %c", &tanla);
    input_check();
    box[qator][ustun] = tanla;
}

void togrilikka_check()
{
    while (box[qator][ustun] != checkbox[qator][ustun])
    {
        system("COLOR 0C");
        show_table();
        printf("\nNoto'gri son tanladingiz !!!!!!!\n");
        tanlamoq();
    }
    if (box[qator][ustun] == checkbox[qator][ustun])
    {
        system("cls");
        system("COLOR 0a");
        show_table();
        printf("\nZo'r tanlov keyingisini tanlashingiz mumkin\n");
    }
}

bool boshkatak()
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (box[i][j] == ' ')
                count++;
        }
    }

    if (count != 0)
        return true;
    else
        return false;
}