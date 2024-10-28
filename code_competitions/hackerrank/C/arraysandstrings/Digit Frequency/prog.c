#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char c;
    int counter[10] = {0};
    while(scanf("%c",&c) == 1){
        if(c >= '0' & c <= '9'){
            counter[c - '0']++;
        }
    }
    int i;
    for(i = 0; i < 10; i++){
        printf("%d ",counter[i]);
    }
    return 0;
}
