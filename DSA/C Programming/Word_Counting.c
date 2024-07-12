#include <stdio.h>
#define IN 1
#define OUT 0 // do not add semicolon at the end of the #define statement

int main()
{

    int c;
    int count = 0;
    int word = 0;
    int nl = 0;
    int state = OUT;
    int nDigit[10];

    for (int i = 0; i < 10; i++)
    {
        nDigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        putchar(c);
        count++;
        if (c >= '0' && c <= '9')
        {
            nDigit[c - '0']++;
        }
        if (c == '\n' || c == '\t' || c == ' ')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            word++;
        }
        if (c == '\n')
        {
            nl++;
        }
    }
    printf("The number of characters are: %d \n", count);
    printf("The number of words are: %d \n", word);
    printf("The number of new lines are %d \n", nl);
    for (int i = 0; i < 10; i++)
    {
        if (nDigit[i])
        {
            printf("The number of occurences for this digit %d", i);
            printf(" are %d\n", nDigit[i]);
        }
    }
    return 0;
}