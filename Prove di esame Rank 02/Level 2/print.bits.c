#include <unistd.h>

void	print_bits(unsigned char octet)
{
    char bit;
    int i;

    i = 8;
    while (i --)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}
int main()
{
    unsigned char value = 2; // Passiamo il valore 2
    print_bits(value);       // Chiamata alla funzione per stampare i bit
    write(1, "\n", 1);       // Aggiungi una nuova riga per separare l'output
    return 0;
}