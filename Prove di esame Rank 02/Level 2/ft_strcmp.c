#include <unistd.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (0);
    while (s1[i])
        i++;
    while (s2[j])
        j++;
    if (i == j)
        return (0);
    else 
        return (i - j);
}

#include <stdio.h>
int main()
{
    char s1[] = "ao";
    char s2[] = "ciao";
    printf("%d", ft_strcmp(s1,s2));
    return(0);
}