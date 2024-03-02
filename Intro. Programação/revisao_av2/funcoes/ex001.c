#include <stdio.h>
#include <locale.h>

void sort(int *a, int *b, int *c)
{
    if (*a > *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
    if (*b > *c)
    {
        *b = *b + *c;
        *c = *b - *c;
        *b = *b - *c;
    }
    if (*a > *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int x, y, z;
    printf("Digite x, y e z: ");
    scanf("%d%d%d", &x, &y, &z);

    sort(&x, &y, &z);
    printf("Valores ordenados: X=%d, Y=%d, Z=%d", x, y, z);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
