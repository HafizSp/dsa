#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins to make change
int minCoins(int coins[], int n, int amount)
{
    // Create an array to store the minimum number of coins for each amount
    int dp[amount + 1];

    // Initialize the array with a large value (representing infinity)
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }

    // Base case: 0 coins are needed to make change for 0
    dp[0] = 0;

    // Fill the array using bottom-up dynamic programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    // If dp[amount] is still INT_MAX, no combination of coins can make the amount
    if (dp[amount] == INT_MAX)
    {
        return -1;
    }

    // Return the minimum number of coins needed to make the given amount
    return dp[amount];
}

int main()
{
    int coins[] = {4, 10, 25}; // Denominations of coins
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 41; // Amount for which we want to make change

    int result = minCoins(coins, n, amount);

    if (result != -1)
    {
        printf("Minimum number of coins needed to make change for %d: %d\n", amount, result);
    }
    else
    {
        printf("It's not possible to make change for %d using the given coins.\n", amount);
    }

    return 0;
}
