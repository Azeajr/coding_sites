#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int and , or, xor;
  and = or = xor = 0;

  int i,j, temp = 0;
  for(i = 1; i <= n; i++){
      for(j = i+1; j <= n; j++){
          temp = i&j;
          if(temp < k && temp > and){
              and = temp;
          }
          temp = i|j;
          if(temp < k && temp > or){
              or = temp;
          }
          temp = i^j;
          if(temp < k && temp > xor){
              xor = temp;
          }
      }
  }

  printf("%d\n%d\n%d\n", and, or, xor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
