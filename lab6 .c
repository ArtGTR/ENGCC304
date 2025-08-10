#include <stdio.h>


int main  () {
    int n;
    int i;
    
    printf ("input your num:");
    scanf ("%d" ,&n );

    if (n % 2 == 1) {
       for (i = 1 ; i <= n ; i ++) {
           if (i % 2 == 1){
           printf("%d",i);
           }
       }
    }else {
        for (i = n ; i > 0 ; i--){
            if (i % 2 == 0) {
            printf( "%d",i);
            }
        }
    }
}              