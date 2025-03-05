#include <unistd.h>
#include <stddef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    if (!s1 || !s2)
        return(0);
    while (s1[i])
    {
        j = 0;
        while(s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return(NULL);
}
#include <stdio.h>
int main()
{
    char s1[] = "ciao";
    char s2[] = "";
    printf("%s", ft_strpbrk(s1,s2));
    return(0);
}