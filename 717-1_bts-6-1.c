#include <stdio.h>

int func1(int *arr, int arr_len) {
    int d = arr_len, i, temp;
    int bl = 1;
    while (d > 1 || bl){
            if (d > 1){
                d /= 1.24733;
            }
            else{
                d = 1;
            }
            bl = 0;
            for (i = 0; i + d < arr_len; ++i){
                if (arr[i + d] > arr[i]){
                    temp = arr[i];
                    arr[i] = arr[i + d];
                    arr[i + d] = temp;
                    bl = 1;
                }
            }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    func1(a, n);
    for(int i = 0; i < n; ++i){
        if(i!=n-1){
            printf("%d", a[i]);
            printf(" ");
        }
        else{
            printf("%d", a[i]);
        }
    }
    printf("\n");
}
