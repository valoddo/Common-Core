#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char bit;
    int i;

    i = 8;
    while(i --)
    {
        bit = (bit << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return (bit);
}
#include <stdio.h>

void print_bits(unsigned char octet)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (octet >> i) & 1);
}

int main()
{
    unsigned char value = 0b00100110; // 38 in decimale
    unsigned char reversed = reverse_bits(value);

    printf("Originale: ");
    print_bits(value);
    printf("\nInvertito: ");
    print_bits(reversed);
    printf("\n");

    return 0;
}
