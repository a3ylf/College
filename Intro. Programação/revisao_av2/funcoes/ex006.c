#include <stdio.h>
#include <locale.h>

void multiply(int x, int a, double *s)
{
    double mult = x;
    for (int i = 0; i < 20; i++)
    {
        *s += ((double)(i + 1) / (a - i)) * ((20 - i) / mult);
        mult *= x;
    }
}

void showMultiplication(int x, int a, double s)
{
    double mult = x;
    int i;

    if (a >= 0 && a <= 19 || x == 0)
        printf("\nHouve divisão por 0, por isso o resultado é indefinido");
    else
    {
        printf("S = ");
        for (i = 0; i < 19; i++)
        {
            printf("(%d / %d) * (%d / %.0f) + ", i + 1, a - i, 20 - i, mult);
            mult *= x;
        }
        printf("(%d / %d) * (%d / %.0f) = %.2f", i + 1, a - i, 20 - i, mult, s);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int x, a;
    double s = 0;
    printf("Informe o X e o A: ");
    scanf("%d%d", &x, &a);

    multiply(x, a, &s);
    showMultiplication(x, a, s);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
