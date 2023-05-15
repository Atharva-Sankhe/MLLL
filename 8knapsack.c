#include<stdio.h>

struct knapsack
{
    float profit, weight, ratio;
    int item_no;
} d[100];

void swap(struct knapsack *x, struct knapsack *y)
{
    struct knapsack temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void main()
{
    int n, capacity, counter = 0;
    float WEIGHT = 0, PROFIT = 0, fractional, SOLUTION[100];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter max capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++)
    {
        d[i].item_no = i + 1;
        printf("Profit, Weight: ");
        scanf("%f %f", &d[i].profit, &d[i].weight);
        d[i].ratio = d[i].profit / d[i].weight;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (d[j].ratio < d[j + 1].ratio)
                swap(&d[j], &d[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (capacity > d[i].weight)
        {
            SOLUTION[d[i].item_no - 1] = 1;
            // WEIGHT = WEIGHT + d[i].weight;
            // PROFIT = PROFIT + d[i].profit;
            capacity = capacity - d[i].weight;
        }
        else
        {
            fractional = capacity / d[i].weight;
            // WEIGHT = WEIGHT + d[i].weight * fractional;
            // PROFIT = PROFIT + d[i].weight * fractional;
            SOLUTION[d[i].item_no - 1] = fractional;
            break;
        }
    }

    for (int j = 0; j < n; j++)
        printf("%f\t", SOLUTION[j]);
}
