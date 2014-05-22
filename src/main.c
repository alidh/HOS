#include "HOS.h"

uint8 *memcpy(uint8 *dest, const uint8 *src, int count)
{
    int i = 0;
start_cpy:
    *(dest+i) = *(src+i);
    i = i + 1;
    if (i < count)
       goto start_cpy;
    return dest;
    /* Add code here to copy 'count' bytes of data from 'src' to
    *  'dest', finally return 'dest' */
}

uint8 *memset(uint8 *dest, uint8 val, int count)
{
    int i = 0;
start_set:
    *(dest+i) = val;
    i = i + 1;
    if (i < count)
	goto start_set;
    return dest;
    /* Add code here to set 'count' bytes in 'dest' to 'val'.
    *  Again, return 'dest' */
}

uint16 *memsetw(uint16 *dest, uint16 val, int count)
{
    int i = 0;
start_set:
    dest[i] = val;
    i = i + 1;
    if (i < count)
	goto start_set;
    return dest;
    /* Same as above, but this time, we're working with a 16-bit
    *  'val' and dest pointer. Your code can be an exact copy of
    *  the above, provided that your local variables if any, are
    *  unsigned short */
}

int strlen(const char *str)
{
    int i = 0;
    for (; str[i] != 0; i = i+1);
    return i;
    /* This loops through character array 'str', returning how
    *  many characters it needs to check before it finds a 0.
    *  In simple words, it returns the length in bytes of a string */
}

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
uint8 inportb (uint16 _port)
{
    uint8 rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (uint16 _port, uint8 _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

/* This is a very simple main() function. All it does is sit in an
*  infinite loop. This will be like our 'idle' loop */
void main()
{
    /* You would add commands after here */
    /* ...and leave this loop in. There is an endless loop in
    *  'start.asm' also, if you accidentally delete this next line */
    for (;;);
}
