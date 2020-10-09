#include <stdio.h>

int main(void)
{
    char    a, *pa;
    int     b, *pb;
    float   c, *pc;
    double  d, *pd;

    printf("size of a  = %dbyte\n", sizeof(a));
    printf("size of pa = %dbyte\n\n", sizeof(pa));

    printf("size of b  = %dbyte\n", sizeof(b));
    printf("size of pb = %dbyte\n\n", sizeof(pb));

    printf("size of c  = %dbyte\n", sizeof(c));
    printf("size of pc = %dbyte\n\n", sizeof(pc));

    printf("size of d  = %dbyte\n", sizeof(d));
    printf("size of pd = %dbyte\n\n", sizeof(pd));

    return 0;
}
