/* bufdemo.c  --  CS 270 buffer-overflow teaching demo
 *
 * Replicates the CS:APP "bufdemo-nsp" behavior:
 *   - short input  -> program echoes it and returns normally
 *   - long  input  -> return address gets clobbered -> Segmentation Fault
 *
 * WARNING: this code is DELIBERATELY BROKEN. gets() has no bounds check and
 * was removed from the C standard in C11. Never use it in real code.
 *
 * To reproduce the slide, defeat the compiler's safety nets:
 *   gcc -O0 -fno-stack-protector -no-pie -z execstack -o bufdemo-nsp bufdemo.c
 *
 * The important flag is -fno-stack-protector (that is the "-nsp").
 * With the default stack protector on, a long input aborts with
 * "*** stack smashing detected ***" instead of a raw segfault.
 */

#include <stdio.h>

/* gets() may not be declared by modern <stdio.h>; declare it ourselves. */
char *gets(char *s);

/* Echo Line */
void echo()
{
    char buf[4];        /* Way too small! */
    gets(buf);          // read in a line
    puts(buf);          // print it out
}

void call_echo()
{
    echo();
}

int main()
{
    printf("Type a string:");
    fflush(stdout);
    call_echo();
    return 0;
}
