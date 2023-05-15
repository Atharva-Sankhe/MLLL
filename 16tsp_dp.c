// #include <stdio.h>
// int a[10][10], visited[10], n, cost = 0;

// void get()
// {
//     int i, j;
//     printf("Enter No. of Cities: ");
//     scanf("%d", &n);
//     printf("\nEnter Cost Matrix\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("\nEnter Elements of Row #: %d\n", i + 1);
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d",&a[i][j]);
//         }
        
//         visited[i] = 0;
//     }

//     printf("\n\nThe cost list is:\n\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("\n\n");
//         for (j = 0; j < n; j++)
//         {
//             printf("\t%d", a[i][j]);
//         }
//     }
// }

// void mincost(int city)
// {
//     int i, ncity;
//     visited[city] = 1;
//     printf("%d -->", city + 1);
//     ncity = least(city);
//     if (ncity == 999)
//     {
//         ncity = 0;
//         printf("%d", ncity + 1);
//         cost += a[city][ncity];
//         return;
//     }
//     mincost(ncity);
// }
// int least(int c)
// {
//     int i, nc = 999;
//     int min = 999, kmin;
//     for (i = 0; i < n; i++)
//     {
//         if ((a[c][i] != 0) && (visited[i] == 0))
//             if (a[c][i] < min)
//             {
//                 min = a[i][0] + a[c][i];
//                 kmin = a[c][i];
//                 nc = i;
//             }
//     }
//     if (min = 999)
//         cost += kmin;
//     return nc;
// }
// void put()
// {
//     printf("\n\nMinimum cost:");
//     printf("%d", cost);
// }

// void main()
// {
//     get();
//     printf("\n\nThe Path is: \n\n");
//     mincost(0);
// }

#include <stdio.h>

#define MAX_CITIES 10
#define INF 999999

int costMatrix[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int numCities;
int totalCost = 0;

void getInput()
{
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    
    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < numCities; i++)
    {
        printf("\nEnter elements of Row #%d:\n", i + 1);
        for (j = 0; j < numCities; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
        visited[i] = 0;
    }
    
    printf("\n\nThe cost matrix is:\n\n");
    for (i = 0; i < numCities; i++)
    {
        printf("\n\n");
        for (j = 0; j < numCities; j++)
        {
            printf("\t%d", costMatrix[i][j]);
        }
    }
}

void findMinCost(int currentCity)
{
    int i, nextCity;
    visited[currentCity] = 1;
    printf("%d -->", currentCity + 1);
    
    nextCity = findNextCity(currentCity);
    if (nextCity == INF)
    {
        nextCity = 0;
        printf("%d", nextCity + 1);
        totalCost += costMatrix[currentCity][nextCity];
        return;
    }
    findMinCost(nextCity);
}

int findNextCity(int city)
{
    int i, nextCity = INF;
    int minCost = INF, currentCost;
    
    for (i = 0; i < numCities; i++)
    {
        if ((costMatrix[city][i] != 0) && (visited[i] == 0))
        {
            currentCost = costMatrix[city][i];
            if (currentCost < minCost)
            {
                minCost = currentCost;
                nextCity = i;
            }
        }
    }
    
    if (minCost == INF)
        totalCost += costMatrix[city][0];
    
    return nextCity;
}

void displayResult()
{
    printf("\n\nMinimum cost: %d", totalCost);
}

int main()
{
    getInput();
    printf("\n\nThe path is: \n\n");
    findMinCost(0);
    displayResult();

    return 0;
}