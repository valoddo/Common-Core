#include <unistd.h>

int	max(int *tab, unsigned int len)
{
	static int	max;

	if (len <= 0x0 || !tab)
		return (0x0);
	len--;
	max = tab[len];
	while (len--)
		if (tab[len] > max)
			max = tab[len];
	return (max);
}
#include <stdio.h>

int main()
{
    int a[3] = {4,2,5};
    int b = max(a, 3);
    printf("%d", b);
    return(0);
}
