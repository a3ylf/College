#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int m[][4])
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] = rand() % 100;
    return;
}

void show(int m[][4])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

int bigger30(int m[][4])
{
    int tot = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (m[i][j] > 30)
                tot++;
    return tot;
}

void fillSecond(int mo[][4], int md[][4])
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (mo[i][j] == 30)
                md[i][j] = 0;
            else
                md[i][j] = mo[i][j];
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int m[6][4], m2[6][4];
    fill(m);
    printf("Matriz M:\n");
    show(m);

    printf("\n%d elementos dessa matriz são maiores que 30\n\n", bigger30(m));

    fillSecond(m, m2);
    printf("Segunda Matriz:\n");
    show(m2);

    getchar();
    return 0;
}
