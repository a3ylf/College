#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(float m[][3])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] = 10 - (float)(rand() % 1000) / 100;
}

void worst(float m[][3], int worst[], int total[])
{
    int tot1 = 0, tot2 = 0, tot3 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (m[i][0] < m[i][1] && m[i][0] < m[i][2])
            worst[i] = 0;
        if (m[i][1] < m[i][0] && m[i][1] < m[i][2])
            worst[i] = 1;
        if (m[i][2] < m[i][0] && m[i][2] < m[i][1])
            worst[i] = 2;
    }

    for (int i = 0; i < 10; i++)
    {
        if (worst[i] == 0)
            tot1++;
        if (worst[i] == 1)
            tot2++;
        if (worst[i] == 2)
            tot3++;
    }
    total[0] = tot1;
    total[1] = tot2;
    total[2] = tot3;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    float grades[10][3];
    int worstG[10], total[3];
    
    fill(grades);
    printf("Notas:\n");
    printf("No          1o     2o     3o\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%-7d", i + 1);
        for (int j = 0; j < 3; j++)
            printf("%7.2f", grades[i][j]);
        printf("\n");
    }

    worst(grades, worstG, total);
    printf("\nPiores notas:\n");
    printf("Aluno    Prova\n");
    for (int i = 0; i < 10; i++)
        printf("%-7d%7d\n", i + 1, worstG[i] + 1);
    printf("\nMenores notas na:\n");
    printf("1o Prova: %d\n2o Prova: %d\n3o Prova: %d", total[0], total[1], total[2]);

    getchar();
    return 0;
}
