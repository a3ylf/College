#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int m[][20])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 20; j++)
            m[i][j] = 10 - rand() % 20;
}

void show(int m[][20])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
            printf("%+6d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void sumLin(int m[][20], int v[])
{
    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = 0; j < 20; j++)
            sum += m[i][j];
        v[i] = sum;
    }
}

void multiplyMat(int m[][20], int v[])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 20; j++)
            m[i][j] *= v[i];
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int m[10][20], sum[10];
    fill(m);
    printf("Matriz M:\n");
    show(m);

    sumLin(m, sum);
    multiplyMat(m, sum);

    printf("Vetor Soma: ");
    for (int i = 0; i < 10; i++)
        printf("%+6d", sum[i]);
    printf("\n\n");

    printf("Matriz Resultante:\n");
    show(m);

    getchar();
    return 0;
}
