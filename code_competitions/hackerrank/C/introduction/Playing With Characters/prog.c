#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    char ch;
    scanf("%c", &ch);

    char s[100];
    /*
     * The blank after the s is used to have scanf ignore any whitespace characters
     */
    scanf("%s ", s);

    char sentence[1000];
    scanf("%[^\n]%*c", sentence);



    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n",sentence);



    return 0;
}
