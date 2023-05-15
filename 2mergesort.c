#include<stdio.h>
void merge(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    int len1=mid+1-s;
    int len2=e-mid;
    int arr1[len1],arr2[len2];
    int k=s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i]=arr[k++];
    }
    k=mid+1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i]=arr[k++];
    }
    int index1=0,index2=0;
    k=s;
    while (index1<len1 && index2<len2)
    {
        if (arr1[index1]>arr2[index2])
        {
            arr[k++]=arr2[index2++];
        }
        else
        {
            arr[k++]=arr1[index1++];
        }
       
        
    }
     while (index1<len1)
        {
            arr[k++]=arr1[index1++];
        }
        while (index2<len2)
        {
            arr[k++]=arr2[index2++];
        }
        
    
}
void mergesort(int *arr,int s,int e)
{
    if (s>=e)
    {
        return;
    }
    
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
    int arr[]={5,4,3,2,1};
    int n=5;
    mergesort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
    
}