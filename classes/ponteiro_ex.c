#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float a = 20.8, *p, b = 15.17, *q;
    p = &a; q = &b;

    printf("\n\na = %g; b = %g;\n", a, b);
    printf("p = &a = %ld; q = &b = %ld;\n", p, q);
    printf("&p = %ld; &q = %ld;\n", &p, &q);
    printf("a = %g; *p = %g ;\n", a, *p);
    printf("b = %g; *q = %g ;\n", b, *q);

    *q = *p + 2;

    printf("\n\na = %g; *p = %g ;\n", a, *p);
    printf("b = %g; *q = %g ;\n", b, *q);

    p = q;

    printf("\n\na = %g; *p = %g ;\n", a, *p);
    printf("b = %g; *q = %g ;\n", b, *q);

    return 0;

}