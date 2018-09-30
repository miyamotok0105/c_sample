//gcc hoge.c
//a.out

#include <stdio.h>
#include <stdlib.h>

//キャラクター端末に対して文字を出力する以外に決まった命令をすることができる。
//例えば007を出力すると音がなる。

int
main(int argc, char *argv[])
{
    printf("\007");

    exit(0);
}
