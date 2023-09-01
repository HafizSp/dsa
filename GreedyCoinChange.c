#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int greedyCoinChange(int arr[], int n, int amount)
{

    bubbleSort(arr, n);
    int remaining_coin = amount;
    int number_of_coin;
    int coin_count = 0;

    for (int i = 0; i < n; i++)
    {
        number_of_coin = remaining_coin / arr[i];

        if (number_of_coin > 0)
        {
            printf("%d x %d\n", arr[i], number_of_coin);
            coin_count += number_of_coin;
        }

        remaining_coin -= number_of_coin * arr[i];
    }
    return coin_count;
}

int main()
{
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(int);
    int amount = 67;
    int totalCoin = greedyCoinChange(coins, n, amount);
    printf("Total coin needed = %d", totalCoin);
}