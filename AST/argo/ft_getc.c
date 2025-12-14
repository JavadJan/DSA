#include <stdio.h>

int main(void) {
    FILE *f = fopen("test.txt", "r");
    if (!f) return 1;

    int c;
    while ((c = getc(f)) != EOF) {
        putchar(c);  // print each character to stdout
    }
	putchar('\n');
    fclose(f);
}
