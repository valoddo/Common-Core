#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t j;

    i = 0;
    if (!s || !reject)
        return(0);
    while (s[i])
    {
        j = 0;
        while(reject[j])
        {
            if (s[i] == reject[j])
                return(i);
            j++;
        }
        i++;
    }
    return(i);
}

#include <stdio.h>
int main()
{
    char s[] = "ciao";
    char reject[] = "hello";
    printf("%d", ft_strcspn(s,reject));
    return(0);
}