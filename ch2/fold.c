#include <stdio.h>
#include <string.h>

#define SIZE 1024
#define TABSTOP 4
#define N 10

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

int findspace(char *s)
{
    int i = 0;
    int col = 0;
    int last = -1;
    while (col <= N)
    {
        switch (s[i])
        {
        case '\t':
            col += TABSTOP - 1;
        case ' ':
            last = i;
        default:
            col++;
        }
        i++;
    }
    return last;
}

void foldln(char *s)
{
    int len = strlen(s);
    int i;
    while (len > 0)
    {
        // If rest of line is shorter than col limit
        if (len <= N)
        {
            // Print it and return
            printf("%s", s);
            return;
        }
        // Else fold
        else
        {
            i = findspace(s);
            // If line is too long
            if (i == -1)
            {
                // Split at col N
                for (int j = 0; j < N; j++)
                    putchar(s[j]);
                putchar('\n');
                len -= N;
                s += N;
            }
            else
            {
                // Split at last whitespacd and don't print it
                s[i] = '\0';
                puts(s);
                len -= i + 1;
                s += i + 1;
            }
        }
    }
}

int main(void)
{
    char buf[SIZE];
    while (mygetline(buf, SIZE) != 0)
        foldln(buf);
}
