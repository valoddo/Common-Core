#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char stamp[256] = {0};

    i = 0;
    j = 0;
    if (argc == 3)
    {
        while (argv[2][j])
	    {
		    stamp[(int)argv[2][j]] = 1;
		    j++;
	    }
	    while (argv[1][i])
	    {
		    if (stamp[(int)argv[1][i]] == 1)
		    {
			    write(1, &argv[1][i], 1);
			    stamp[(int)argv[1][i]] = 0;
		    }
		    i++;
	    }
    }
    write(1, "\n", 1);
    return(0);
}
