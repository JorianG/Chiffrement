#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'a';
    if (isalnum(c)) {
        printf("%c est un caractère alphanumérique.\n", c);
    } else {
        printf("%c n'est pas un caractère alphanumérique.\n", c);
    }
    return 0;
}


