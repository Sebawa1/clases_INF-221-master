/*
 * The hash function as used in the Unix ELF format
 * Unix System Laboratories, "System V Application Binary Interface",
 * Prentice Hall (1993)
 * A variant of Peter J. Weinberger's function, specialized to 32 bits
 */

unsigned long ElfHash(const unsigned char *s)
{
    unsigned long h = 0, high;
    while(*s) {
        h = (h << 4) + *s++;
        if((high = h & 0xF0000000))
            h ^= high >> 24;
        h &= ~high;
    }
    return h;
}
