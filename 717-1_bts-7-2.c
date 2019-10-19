#include <stdio.h>
#include <stdlib.h>

void funcdown(int arr[], int first, int choose){
    int max=0,flag=0;
    while ((first*2+1<=choose) && (!flag)){
        if (first*2+1==choose)
            max=first*2+1;
        else if (arr[first*2+1]>arr[first*2+2])max=first*2+1;
             else max=first*2+2;
            if (arr[first]<arr[max]){
                int temp=arr[first];
                arr[first]=arr[max];
                arr[max]=temp;
                first=max;
            }
            else flag=1;
    }
}

void funcsort(int arr[], int size){
    int temp=0;
    for(int i=(size/2)-1; i>=0; i--)
    funcdown(arr,i,size-1);
    for(int i=size-1; i>=1; i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        funcdown(arr,0,i-1);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    funcsort(arr,n);
    for(int i=0;i<n;i++)
    {
    printf("%d",arr[i]);
    if (i==n-1)
    printf("\n");
    else
    printf(" ");
    }
    return 0;
}

