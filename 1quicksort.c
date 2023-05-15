#include<stdio.h>

void swap(int arr[] ,int a , int b){
    int t = arr[a];
    arr[a] = arr[b];
    arr[b]= t;
}

int partition(int arr[],int s , int e)
{
    int pivot = arr[s],count = 0;
    for (int i = s+1; i <= e ; i++)
    {
        if (arr[i]<=pivot)
        {
            count++;
        }
        
    }
    int pivot_index = s+count;
    swap(arr, pivot_index, s);
    int i=s,j=e;
    while (i<pivot_index && j>pivot_index)
    {
        while (arr[i] > arr[pivot_index])
        {
            i++;
        }
        while (arr[j] < arr[pivot_index])
        {
            j--;
        }
        if (i<pivot_index && j>pivot_index)
        {
            swap(arr,i,j);
        }
    }
    
    return pivot_index;
}

void quicksort(int arr[],int s,int e)
{
    if (s>=e)
    {
        return ;
    }
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main()
{
    int arr[] = {6,5,4,3,2,1};
    quicksort(arr,0,5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d",arr[i]);
    }
    
    return 0;
}