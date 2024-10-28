#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    double c, d;
    scanf("%lf", &c);
    scanf("%lf", &d);

    printf("%d %d\n", a+b, a-b);
    printf("%.1lf %.1lf\n", c+d, c-d);


    return 0;
}
