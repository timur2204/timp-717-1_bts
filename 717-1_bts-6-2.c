#include <stdio.h>

int func2(int *arr, int arr_len) {
    int i, j, k;
	int temp;
	for(k = arr_len / 2; k > 0; k /= 2){
        for(i = k; i < arr_len; i++)
        {
            temp = arr[i];
            for(j = i; j >= k; j -= k)
            {
                if(temp < arr[j - k])
                    arr[j] = arr[j - k];
                else
                    break;
            }
            arr[j] = temp;
        }
	}
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    func2(a, n);
    for(int i = 0; i < n; i++){
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
