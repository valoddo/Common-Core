#include <unistd.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int i = 1;
    int x = 0;
    int tmp = tab[0];

    if (!tab || size < 0)
        return;
    while (x < size - 1)
    {
        i = 1;
        while (i < size)
        {
            if (tab [i - 1] > tab[i])
            {
                tmp = tab[i];
                tab[i] = tab[i -1];
                tab [i -1] = tmp;
            }
            i++;
        }
        x++;
    }
}

#include <stdio.h>

int main()
{
    int arr[] = {3, 67, 5};
    int n = 2;
    int i = 0;
    sort_int_tab(arr, n);
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    return(0);
}