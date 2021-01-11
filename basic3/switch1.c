#include <stdio.h>

int main(void) {

    int  a;

    for(a=1; a<=5; a++){
        printf("-------------\n");
        switch(a){
            case 1:
                printf("a=1\n");
            case 3:
                printf("a=3\n");
            case 5:
                printf("a=5\n");
            default :
                printf("others\n");
        }
    }
    return 0;
}
