#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define arrLen(arr) (sizeof(arr) / sizeof(arr[0]))

void fill(int v[])
{
    for (int i = 0; i < 15; i++)
        v[i] = rand() % 100;
}

void show(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", v[i]);
}

int prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    if (n == 0 || n == 1)
        return 0;
    return 1;
}

int onlyPrimes(int v[], int size, int p[])
{
    int pos = 0;
    for (int i = 0; i < size; i++)
        if (prime(v[i]))
            p[pos++] = v[i];
    return pos;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int v[15], p[15] = {0}, sizeP;

    fill(v);
    sizeP = onlyPrimes(v, arrLen(v), p);
    printf("Vetor V: ");
    show(v, arrLen(v));
    printf("\n\nVetor de Primos: ");
    show(p, sizeP);

    getchar();
    return 0;
}
