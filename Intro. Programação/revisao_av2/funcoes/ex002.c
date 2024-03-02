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

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    if (prime(n))
        printf("O número %d É primo", n);
    else
        printf("O número %d NÂO É primo", n);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
