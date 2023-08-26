#include <stdio.h>
#include <stdlib.h>

void print(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", arr[i]);
    }
}

void bubbleSort(double profit[], double weight[], double p2w[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (p2w[j] < p2w[j + 1])
            {
                profit[j + 1] = profit[j] + profit[j + 1] - (profit[j] = profit[j + 1]);
                weight[j + 1] = weight[j] + weight[j + 1] - (weight[j] = weight[j + 1]);
                p2w[j + 1] = p2w[j] + p2w[j + 1] - (p2w[j] = p2w[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(double profit[], double weight[], int maxWeight, int n)
{
    double p2w[n];
    for (int i = 0; i < n; i++)
    {
        p2w[i] = profit[i] / weight[i];
    }

    // print(p2w, n);
    // printf("\n");
    // print(profit, n);
    // printf("\n");
    // print(weight, n);
    // printf("\n");
    // printf("\n");

    bubbleSort(profit, weight, p2w, n);

    // print(p2w, n);
    // printf("\n");
    // print(profit, n);
    // printf("\n");
    // print(weight, n);
    // printf("\n");

    double totalProfit = 0;
    int remainingWeight = maxWeight;

    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= remainingWeight)
        {
            remainingWeight -= weight[i];
            totalProfit += profit[i];
        }
        else
        {
            double fraction = (double)remainingWeight / weight[i];
            totalProfit += (profit[i] * fraction);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    // double profit[] = {10, 15, 10, 20, 8};
    // double weight[] = {3, 3, 2, 5, 1};
    // int n = sizeof(profit) / sizeof(double);
    // double maxWeight = 10;

    int maxWeight;
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &maxWeight);

    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    double profit[n];
    printf("Enter all the profit: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &profit[i]);
    }

    double weight[n];
    printf("Enter all the weight: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &weight[i]);
    }

    double result = fractionalKnapsack(profit, weight, maxWeight, n);
    printf("%0.2lf", result);
}