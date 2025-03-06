#include <unistd.h>
#include <stdlib.h>


int     *ft_range(int start, int end)
 {
    int i;
    int size;
    int *arr;

    i = 0;
    if (start > end)
      size = (start - end) + 1;
   else 
      size = (end - start) + 1;
    arr = malloc(sizeof(int) * size);
    if(!arr)
      return(NULL);
   if (start > end)
   {
      while (i < size)
      {
         arr[i] = start;
         start = start - 1;
         i++;
      }
   }
   else
   {
      while (i < size)
      {
         arr[i] = start;
         start = start + 1;
         i++;
      }
   }
   return (arr);
 }

 #include <stdio.h>

 int main()
 {
   int nb1 = 0;
   int nb2 = -3;
   int i = 0;
   int *array;
   array = ft_range(nb1, nb2);
   while (i < (nb1 - nb2 + 1))
   {
      printf("%d", array[i]);
      i++;
   }
   return(0);
 }
