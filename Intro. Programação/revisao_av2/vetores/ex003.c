#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define arrLen(arr) (sizeof(arr) / sizeof(arr[0]))

void fill(int v[], int size)
{
    for (int i = 0; i < size; i++)
        v[i] = 10 - rand() % 20;
}

void show(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%+3d ", v[i]);
}

int onlyPositives(int v[], int size, int p[])
{
    int pos = 0;
    for (int i = 0; i < size; i++)
        if (v[i] >= 0)
            p[pos++] = v[i];
    return pos;
}

int onlyNegatives(int v[], int size, int n[])
{
    int pos = 0;
    for (int i = 0; i < size; i++)
        if (v[i] < 0)
            n[pos++] = v[i];
    return pos;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int v[8], p[8] = {0}, n[8] = {0}, sizeP, sizeN;
    fill(v, arrLen(v));
    printf("Vetor V: ");
    show(v, arrLen(v));
    sizeP = onlyPositives(v, arrLen(v), p);
    sizeN = onlyNegatives(v, arrLen(v), n);

    printf("\n\nVetor P: ");
    show(p, sizeP);
    printf("\n\nVetor N: ");
    show(n, sizeN);

    getchar();
    return 0;
}