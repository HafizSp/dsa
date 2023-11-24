#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int weights[], int profits[], int W, int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (w < weights[i])
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(profits[i] + dp[i - 1][w - weights[i]], dp[i - 1][w]);

            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }
    int includedItems[n + 1];
    int w = W;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            includedItems[i] = 1;
            w -= weights[i];
        }
        else
            includedItems[i] = 0;
    }
    printf("Included items: \n");

    for (int i = 1; i <= n; i++)
    {
        printf("-------------------\n");
        printf("%d kg | %d\n", weights[i], includedItems[i]);
        printf("-------------------\n");
    }

    return dp[n][W];
}

int main()
{
    int weights[] = {0, 3, 4, 5, 6};
    int profits[] = {0, 2, 3, 4, 1};
    int W = 8; // maximum weight of bag
    int n = 4; // number of items
    printf("Max profits: %d", knapsack(weights, profits, W, n));
    return 0;
}