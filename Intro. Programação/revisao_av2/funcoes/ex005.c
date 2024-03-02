#include <stdio.h>
#include <locale.h>

int sequency(int n)
{
    if (n < 1 || n > 9)
    {
        printf("Número inválido.");
        return -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", i * j);
        printf("\n");
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Digite um número de 1 a 9: ");
    scanf("%d", &n);
    sequency(n);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
