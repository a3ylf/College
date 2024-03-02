#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(float v[])
{
    for (int i = 0; i < 12; i++)
        v[i] = 33 - (float)(rand() % 1100) / 100;
}

void analyseMonthTemp(float v[], int *bM, float *bT, int *sM, float *sT)
{
    *bM = 0;
    *bT = v[0];
    *sM = 0;
    *sT = v[0];

    for (int i = 0; i < 12; i++)
    {
        if (v[i] > *bT)
        {
            *bM = i;
            *bT = v[i];
        }
        if (v[i] < *sT)
        {
            *sM = i;
            *sT = v[i];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    float monthMeanTemp[12], bigTemp, smallTemp;
    int bigMonth, smallMonth;
    fill(monthMeanTemp);

    printf("Temperaturas anuais:\n");
    for (int i = 0; i < 12; i++)
        printf("%02d - %.2f °C\n", i + 1, monthMeanTemp[i]);

    analyseMonthTemp(monthMeanTemp, &bigMonth, &bigTemp, &smallMonth, &smallTemp);

    printf("\nA maior temperatura foi de %.2f °C no mês de ", bigTemp);
    switch (bigMonth)
    {
    case 0:
        printf("janeiro\n");
        break;
    case 1:
        printf("fevereiro\n");
        break;
    case 2:
        printf("março\n");
        break;
    case 3:
        printf("abril\n");
        break;
    case 4:
        printf("maio\n");
        break;
    case 5:
        printf("junho\n");
        break;
    case 6:
        printf("julho\n");
        break;
    case 7:
        printf("agosto\n");
        break;
    case 8:
        printf("setembro\n");
        break;
    case 9:
        printf("outubro\n");
        break;
    case 10:
        printf("novembro\n");
        break;
    case 11:
        printf("dezembro\n");
        break;
    default:
    }

    printf("\nA menor temperatura foi de %.2f °C no mês de ", smallTemp);
    switch (smallMonth)
    {
    case 0:
        printf("janeiro\n");
        break;
    case 1:
        printf("fevereiro\n");
        break;
    case 2:
        printf("março\n");
        break;
    case 3:
        printf("abril\n");
        break;
    case 4:
        printf("maio\n");
        break;
    case 5:
        printf("junho\n");
        break;
    case 6:
        printf("julho\n");
        break;
    case 7:
        printf("agosto\n");
        break;
    case 8:
        printf("setembro\n");
        break;
    case 9:
        printf("outubro\n");
        break;
    case 10:
        printf("novembro\n");
        break;
    case 11:
        printf("dezembro\n");
        break;
    default:
    }

    getchar();
    return 0;
}
