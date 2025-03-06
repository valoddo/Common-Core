#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    int prime;
    int second;
    int result;
    char operator;
    
    prime = atoi(argv[1]);
    second = atoi(argv[3]);
    operator = argv[2][0];
    if (argc == 4)
    {
        if (operator == '+')
            result = prime + second;
        else if (operator == '-')
            result = prime - second;
        else if(operator == '*')
            result = prime * second;
        else if(operator == '/')
            result = prime / second;
        else if(operator == '%')
            result = prime % second;
        printf("%d", result);
    }
    write(1, "\n", 1);
    return (0);
}
