#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int m[][10])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            m[i][j] = rand() % 100;
}

void show(int m[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}

void switchL1_7(int m[][10])
{
    for (int i = 0; i < 10; i++)
    {
        m[1][i] += m[7][i];
        m[7][i] = m[1][i] - m[7][i];
        m[1][i] = m[1][i] - m[7][i];
    }
}

void switchC3_9(int m[][10])
{
    for (int i = 0; i < 10; i++)
    {
        m[i][3] += m[i][9];
        m[i][9] = m[i][3] - m[i][9];
        m[i][3] = m[i][3] - m[i][9];
    }
}

void switchD1_2(int m[][10])
{
    for (int i = 0; i < 10; i++)
    {
        m[i][i] += m[i][9 - i];
        m[i][9 - i] = m[i][i] - m[i][9 - i];
        m[i][i] = m[i][i] - m[i][9 - i];
    }
}

void switchL4_C9(int m[][10])
{
    for (int i = 0; i < 10; i++)
    {
        m[4][i] += m[i][9];
        m[i][9] = m[4][i] - m[i][9];
        m[4][i] = m[4][i] - m[i][9];
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int m[10][10];
    fill(m);
    printf("Matriz M:\n");
    show(m);

    switchL1_7(m);
    switchC3_9(m);
    switchD1_2(m);
    switchL4_C9(m);

    printf("\nNova matriz M:\n");
    show(m);

    getchar();
    return 0;
}
