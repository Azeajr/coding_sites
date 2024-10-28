#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL){
        return 1;
    }

    int i, temp;
    for(i = 0; i < n; i++){
      scanf("%d ", &temp);
      arr[i] = temp;
    }

    temp = 0;
    for(i = 0; i < n; i++){
        temp += arr[i];
    }
    printf("%d", temp);


    return 0;
}
