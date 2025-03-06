#include <unistd.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int i = 0;
    int size;
    int *array;

    if (start < end)
        size = (end - start) + 1;
    else
        size = (start - end) + 1;
    array = malloc(sizeof(int) * (size + 1));
    if (!array)
        return(NULL);
    if (start < end)
        while (i < size)
        {
            array[i] = end;
            end = end - 1;
            i++;
        }
    else
        while (i < size)
        {
            array[i] = end;
            end = end + 1;
            i++;
        }
    return(array);
}

#include <stdio.h>

int main()
{
    int start = -1;
    int end = 2;
    int i = 0;
    int size;
    int *array = ft_rrange(start, end);
    if (start < end)
        size = (end - start) + 1;
    else
        size = (start - end) + 1;
    if (start < end)
        while (i < size)
        {
            printf("%d", array[i]);
            i++;
        }
    return(0);
}