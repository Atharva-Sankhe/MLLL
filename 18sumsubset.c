#include <stdio.h>

void findSubsetSum(int array[], int subset[], int size, int currentIndex, int currentSum,
                   int targetSum, int *count, int *totalSum)
{
    if (currentIndex == size)
    {
        if (currentSum == targetSum)
        {
            printf("{ ");
            for (int i = 0; i < size; i++)
            {
                if (subset[i]==1)
                {
                    printf("%d ", array[i]);
                }
            }
            printf("}\n");
            (*count)++;
            (*totalSum) += currentSum;
        }
        return;
    }

    subset[currentIndex] = 0;
    findSubsetSum(array, subset, size, currentIndex + 1, currentSum, targetSum, count, totalSum);

    subset[currentIndex] = 1;
    findSubsetSum(array, subset, size, currentIndex + 1, currentSum + array[currentIndex], targetSum, count, totalSum);
}

int main()
{
    int array[] = {2,3,5,8,10};
    int size = sizeof(array) / sizeof(array[0]);
    int subset[size];
    int targetSum = 10;
    int count = 0;
    int totalSum = 0;

    findSubsetSum(array, subset, size, 0, 0, targetSum, &count, &totalSum);

    printf("Total number of subsets that add up to %d: %d\n", targetSum, count);
    printf("Total sum of subsets that add up to %d: %d\n", targetSum, totalSum);

    return 0;
}