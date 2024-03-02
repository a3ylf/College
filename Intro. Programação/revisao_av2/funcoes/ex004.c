#include <stdio.h>
#include <locale.h>

float meanGrade(float n1, float n2, float n3, char type)
{
    if (type == 'A' || type == 'a')
        return (n1 + n2 + n3) / 3;
    if (type == 'P' || type == 'p')
        return (n1 * 5 + n2 * 3 + n3 * 2) / 10;

    return -1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float n1, n2, n3, mean;
    char avType;

    printf("Digite as três notas do aluno: ");
    scanf("%f%f%f", &n1, &n2, &n3);
    printf("Escolha um método de avaliação.\n\t- A: Média Aritmética.\n\t- P: Média Ponderada.\n");
    scanf(" %c", &avType);
    mean = meanGrade(n1, n2, n3, avType);
    if (mean == -1)
        printf("Tipo de avaliação inválido.");
    else
        printf("A média do aluno foi de: %.2f", mean);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
