#include <unistd.h>
#include <stdlib.h>

char    *ft_strrev(char *str)
{
    int i;
    int j;
    char *copy;

    i = 0;
    j = 0;
    while(str[i] != '\0')
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy)
        return(NULL);
    while(i--)
    {
        copy[j] = str[i];
        j++;
    }
    copy[j] = '\0';  
    return(copy);
}

#include <stdio.h>
int main()
{
    char *str = "hello";
    char *c;
    c = ft_strrev(str);
    printf("%s", c);
    return(0);
}