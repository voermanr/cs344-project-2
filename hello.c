#include <stdio.h>

int main() {
    int x = 12;
    float y = 3.14f;
    char *s = "Hello, world!\n";

    printf("x is %i, y is %f\n", x,y);
    printf("%s", s);

    for (int i = 0; i < 5; ++i){
        printf("%i x 5 = %i\n", i, i*5);
    }
}
