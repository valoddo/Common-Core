#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

#include <stdio.h>

void print_bits(unsigned char octet)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (octet >> i) & 1);
}

int main()
{
    unsigned char value = 0b01000001; // 65 in decimale ('A' in ASCII)
    unsigned char swapped = swap_bits(value);

    printf("Originale: ");
    print_bits(value);
    printf("\nScambiato: ");
    print_bits(swapped);
    printf("\n");

    return 0;
}