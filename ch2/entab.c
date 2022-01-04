#include <stdio.h>
#include <string.h>

#define SIZE 1024
#define ENTABSIZE (SIZE - 1) * 4 + 1
#define TABSTOP 4

void entabBlock(char *s)
{
    int i;
    for (i = TABSTOP - 1; i >= 0 && s[i] == ' '; i--)
        ;

    if ((TABSTOP - 1 - i) > 1)
    {
        for (int j = 0; j <= i; j++)
        {
            putchar(s[j]);
        }
        putchar('\t');
    }
    else
    {
        for (int j = 0; j < TABSTOP; j++)
        {
            putchar(s[j]);
        }
    }
}

void entabln(char *ln)
{
    int len = strlen(ln);
    int nblocks = len / TABSTOP;
    int i;
    for (i = 0; i < nblocks * TABSTOP; i += TABSTOP)
    {
        entabBlock(ln + i);
    }
    printf("%s", ln + i);
}


int mygetline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int main(void)
{
    char buf[SIZE];
    while (mygetline(buf, SIZE) != 0)
        entabln(buf);
}
