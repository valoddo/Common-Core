#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    char a;
    while (argv[i])
        i++;
    i--;
    a = i + '0';
    write(1, &a, 1);
    return(0);
}