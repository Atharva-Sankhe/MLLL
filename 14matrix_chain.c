#include<stdio.h>
int karr[100][100],p[100];

// int max(int a,int b)
// {
//     if (a>b)
//     {
//         return a ;
//     }
//     else
//     {
//         return b ;
//     }
    
// }
int Mand(int n,int i, int j)
{
    int mink,min=1000000,count=0 ;
    if (i==j)
    {
        mink = 0;
        // karr[i][j]=mink;
        return 0;
    }
    for (int k = i; k < j; k++)
    {
        count = Mand(n,i,k) + Mand(n,k+1,j) + p[i-1] * p[j] * p[k] ;
        if (count < min)
        {
            min = count;
            mink = k ;
        }
    }
    karr[i][j]= mink;
    return min ;

    
}



int main()
{
    int n ;
    printf("Enter the number of sequences: ");
    scanf("%d",&n);
    printf("Enter sequences:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    int q[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            q[i][j]=Mand(n,i,j);
        }
        
    }

    for (int i = 1; i < n; i++)
    {
        for (int m = 0; m < i; m++)
        {
            printf(" ");
        }
        
        for (int j = i; j < n; j++)
        {
            printf("%d ",q[i][j]);
        }
        printf("\n");
        
    }
    for (int i = 1; i < n; i++)
    {
        for (int m = 0; m < i; m++)
        {
            printf(" ");
        }
        
        for (int j = i; j < n; j++)
        {
            printf("%d ",karr[i][j]);
        }
        printf("\n");
        
    }
    
    
    
    
}

