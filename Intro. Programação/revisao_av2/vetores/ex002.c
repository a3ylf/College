#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int v[])
{
    for (int i = 0; i < 10; i++)
        v[i] = 10 - rand() % 20;
}

void show(int v[])
{
    for (int i = 0; i < 10; i++)
        printf("%d ", v[i]);
}

void modify(int vo[], int vd[])
{
    for (int i = 0; i < 10; i++)
        if (i % 2 == 0)
            vd[i] = vo[i] * 5;
        else
            vd[i] = vo[i] + 5;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int a[10], b[10];

    fill(a);
    modify(a, b);

    printf("Vetor A:\n");
    show(a);
    printf("\n\nVetor B:\n");
    show(b);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
