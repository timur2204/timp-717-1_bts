#include <stdio.h>

int main(){
    int n,x;
    int i;
    int count = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
          scanf("%d", &x);
          if (x<0){
          count++;
          }
    }
    printf("%d", count);
}
