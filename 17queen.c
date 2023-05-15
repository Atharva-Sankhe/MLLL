#include <stdio.h>
#include <stdbool.h>

void printSolution(int n, int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int n, int arr[][n], int row, int col)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
        {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void nqueen(int n, int arr[][n], int row)
{
    if (row == n)
    {
        printSolution(n, arr);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(n, arr, row, col))
        {
            arr[row][col] = 1;
            nqueen(n, arr, row + 1);
            arr[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int arr[n][n];

    // Initialize the array with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    nqueen(n, arr, 0);

    return 0;
}
