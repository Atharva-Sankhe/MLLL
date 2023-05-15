#include<stdio.h>

void printMaxActivities(int s[], int f[], int n)
{
    printf("Following activities are selected\n");
    int i = 0;
    printf("%d ", i);
    for (int j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}
 
void main()
{
    int startTime[] = { 1, 3, 0, 5, 8, 5 };
    int finishTime[] = { 2, 4, 6, 7, 9, 9 };
    int n = 6;
    printMaxActivities(startTime, finishTime, n);
}

