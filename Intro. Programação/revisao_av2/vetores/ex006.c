#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int v[])
{
    for (int i = 0; i < 30; i++)
        v[i] = rand() % 30;
}

int find(int v[], int n)
{
    int totN = 0;
    for (int i = 0; i < 30; i++)
        if (v[i] == n)
            totN++;
    return totN;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int v[30], n, totN;
    fill(v);
    printf("Vetor V: ");
    for (int i = 0; i < 30; i++)
        printf("%d ", v[i]);
    
    printf("\n\nDigite um número para ser procurado dentro do vetor: ");
    scanf("%d", &n);
    totN = find(v, n);
    if (totN)
        printf("ACHEI. O número %d aparece %d vezes no vetor", n, totN);
    else
        printf("NÃO ACHEI. O número %d não aparece no vetor", n);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
