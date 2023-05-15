#include<stdio.h>

int compare(int left, int right, int up, int down) {
    int min = left;
    int retuner = 1;
    if (right < min) {
        min = right; 
        retuner = 2;
    }
    if (up < min) {
        min = up; 
        retuner = 3;
    }
    if (down < min) {
        min = down; 
        retuner = 4;
    }
    return retuner;
}

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

void arr_updater(int arr[4][4],int goal[4][4])
{
    int left=99,right=99,up=99,down=99,m,n;
    int lefter[4][4],righter[4][4],upper[4][4],downer[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j]==0)
            {
                m=i;
                n=j;
            }
            
        }
        
    }

    if (n!=0)
    {
        arr_transfer(arr,lefter);
        lefter[m][n]=lefter[m][n-1];
        lefter[m][n-1]=0;
        left=error_cost_finder(lefter,goal);
    }
    if (n!=3)
    {
        arr_transfer(arr,righter);
        righter[m][n]=righter[m][n+1];
        righter[m][n+1]=0;
        right=error_cost_finder(righter,goal);
    }
    if (m!=0)
    {
        arr_transfer(arr,upper);
        upper[m][n]=upper[m-1][n];
        upper[m-1][n]=0;
        up=error_cost_finder(upper,goal);
    }
    if (m!=3)
    {
        arr_transfer(arr,downer);
        downer[m][n]=downer[m+1][n];
        downer[m+1][n]=0;
        down=error_cost_finder(downer,goal);
    }
    

            
    if (compare(left,right,up,down)==1)
    {
        arr_transfer(lefter,arr);
    }
    else if (compare(left,right,up,down)==2)
    {
        arr_transfer(righter,arr);
    }
    else if (compare(left,right,up,down)==3)
    {
        arr_transfer(upper,arr);
    }
    else
    {
        arr_transfer(downer,arr);
    } 

}



int main()
{
    int row,col,arr[4][4],goal[4][4];
    printf("Enter empty position: ");
    scanf("%d %d",&row,&col);
    for (int i = 0; i < 4; i++)
    {
        printf("Enter row: ");
        for (int j = 0; j < 4; j++)
        {   
            scanf("%d",&arr[i][j]);
        }        
    }
    printer(arr);

    int filler=0;
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
    int error=99,change=0;
    while (error!=0)
    {
        arr_updater(arr,goal);
        error = error_cost_finder(arr,goal);
        printer(arr);
    }
    return 0;
}