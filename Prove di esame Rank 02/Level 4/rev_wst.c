#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j;
    int word = 0;
    char *s1;

    if (argc == 2)
    {
        s1= argv[1];
        while(s1[i] != '\0')
            i++;
        i--;
        while (i >= 0)
        {
            while (i >= 0 && (s1[i] == ' ' || (s1[i] >= 9 && s1[i] <= 13)))
                i--;
            j = i;
            while (j >= 0 && s1[j] != ' ' && !(s1[j] >= 9 && s1[j] <= 13))
                j--;
            if (word == 1)
			    write(1, " ", 1);
            write(1, &s1[j + 1], i - j);;
		    word = 1;
		    i = j;
        }

    }
    write (1, "\n", 1);
    return(0);
}