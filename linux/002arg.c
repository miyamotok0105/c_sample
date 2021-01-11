//gcc hoge.c
//a.out a
//a.out a b
//a.out "a b"
//a.out *.c

#include <stdio.h>
#include <stdlib.h>

//argcはコマンドライン引数の数。
//argvは引数の実態の文字列。
//argvの型はcharへのポインタ配列

int
main(int argc, char *argv[])
{
    int i;
    printf("argc=%d\n", argc);
    for(i=0;i<argc;i++){
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    //exit()はプログラムを終了する関数。
    exit(0);
}
