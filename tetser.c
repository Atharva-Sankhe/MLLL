#include<stdio.h>

void printer(int arr[4][4])
{
    printf("\n");
    printf("----------------------------------");
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int arr_transfer(int arr[4][4],int new[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            new[i][j]=arr[i][j];
        }
        
    }
    
}

int error_cost_finder(int arr[4][4],int goal[4][4])
{
    int cost=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != goal[i][j])
            {
                cost++;
            }
            
        }
        
    }
    return cost;
}


int main(){
   int row,col,arr[4][4],goal[4][4];
    printf("Enter empty position: ");
    scanf("%d %d",&row,&col);
    int filler=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i==row && j==col)
            {
                arr[row][col]=0;
                continue;
            }
            filler++;
            arr[i][j]=filler;
            
        }        
    }
    printer(arr);
    filler=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j= 0; j< 4;j++)
        {
            filler++;
            goal[i][j]=filler;
        }
    }
    goal[3][3]=0;
    printer(goal);
    printf("%d",error_cost_finder(arr,goal));
    return 0 ;

}