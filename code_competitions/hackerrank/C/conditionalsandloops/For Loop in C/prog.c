#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.

    char *nums[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    int i;
    for(i = 0; i <= b-a; i++){
        if( a+i >= 1 && a+i <= 9){
            printf("%s\n",nums[a+i-1]);
        } else if((a+i)%2){
            printf("odd\n");
        } else {
            printf("even\n");
        }
    }

    return 0;
}
