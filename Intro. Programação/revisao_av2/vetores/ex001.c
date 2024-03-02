#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(float v[])
{
    for (int i = 0; i < 20; i++)
        v[i] = 10 - (float)(rand() % 2000) / 100;
}

float analyse(float v[], int *p, int *n)
{
    float sum = 0;
    for (int i = 0; i < 20; i++)
    {
        if (v[i] >= 0)
            *p += 1;
        else
            *n += 1;
        sum += v[i];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    float v[20], sum;
    int p = 0, n = 0;

    fill(v);
    printf("O vetor V é formado por: ");
    for (int i = 0; i < 20; i++)
        printf("%+06.2f ", v[i]);

    sum = analyse(v, &p, &n);
    printf("\n\nO vetor tem %d números positivos, %d números negativos e a soma de seus elementos é %+.2f", p, n, sum);

    getchar();
    return 0;
}
