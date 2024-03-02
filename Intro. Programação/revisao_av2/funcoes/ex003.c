#include <stdio.h>
#include <locale.h>

int prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    if (n == 1)
        return 0;
    return 1;
}

int sumPrimeInterval(int a, int b)
{
    int sum = 0;
    for (a; a <= b; a++)
        if (prime(a))
            sum += a;
    return sum;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int x, y;
    while (1)
    {
        printf("Digite o número inicial e o final (os dois iguais para finalizar): ");
        scanf("%d%d", &x, &y);
        if (x == y)
            break;
        if (x > y)
        {
            x = x + y;
            y = x - y;
            x = x - y;
        }
        printf("A soma dos números primos no intervalo [%d, %d] é: %d\n\n", x, y, sumPrimeInterval(x, y));
    }

    printf("\nOperação finalizada com sucesso, pressione Enter para finalizar. ");
    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
