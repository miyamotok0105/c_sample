#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include "ppmlib.h"

void load_color_image( int n, char name[] )
/* カラー画像No.nを出力．name[]が""ならファイル名を入力．   */
{
    char fname[MAX_FILENAME];     /* ファイル名用の文字配列 */
    char buffer[MAX_BUFFERSIZE];  /* データ読込み用変数     */
    FILE *fp;                     /* ファイルポインタ       */
    int max_gray=0,x,y,col;       /* 最大階調値と制御変数   */

    printf("1=========================");
    /* 入力ファイルのオープン */
    if ( name[0]=='\0' ){
        printf("入力ファイル名 (拡張子はppm) : ");
        scanf("%s",fname);
    } else {
        strcpy( fname, name );
    }
    printf("2=========================");
    if ( (fp = fopen( fname, "rb" ))==NULL ){
        printf("ファイルがオープンできませんでした\n");
        exit(1);  /* 強制終了 */
    }
    fgets( buffer, MAX_BUFFERSIZE, fp );
    if ( buffer[0]!='P' || buffer[1]!='6' ){  /* P6の確認 */
        printf("ファイルタイプがP6ではありません\n");
        exit(1);  /* 強制終了 */
    }
    printf("3=========================");
    /* width[n], height[n] の代入（#からのコメントは飛ばす）*/
    width[n] = 0;
    height[n] = 0;
    while ( width[n] == 0 || height[n] == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' ) {
            sscanf( buffer, "%d %d", &width[n], &height[n] );
        }
    }
    printf("4=========================");
    /* max_gray の代入（#からのコメントは読み飛ばす） */
    while ( max_gray == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' ){
            sscanf( buffer, "%d", &max_gray );
        }
    }
    printf("5=========================");
    /* パラメータの画面への表示 */
    printf("横：%d, 縦：%d\n", width[n], height[n] );
    printf("最大階調値 = %d\n",max_gray);
    
    if ( width[n] > MAX_IMAGESIZE_W || height[n] >
        MAX_IMAGESIZE_H ||
        max_gray != MAX_BRIGHTNESS ){
        printf("サイズか最大階調値が不適切です\n");
        exit(1);  /* 強制終了 */
    }
    printf("6=========================");
    /* 画像データを読み込んで画像用配列に代入する */
    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            for(col=0;col<3;col++){
              image[n][x][y][col] = (unsigned char)fgetc( fp );
            }
        }
    }
    printf("カラー画像を画像No.%dに読み込みました．\n",n);

    printf("buffer %hhu", image);

    fclose(fp);
}


void save_color_image( int n, char name[] )
/* n:画像番号，name[]:ファイル名（""のときはキーボード入力）*/
/* 画像の横幅，縦幅はそれぞれ width[n], height[n] に事前に  */
/* 代入されているものとする */
{
    char fname[MAX_FILENAME];  /* ファイル名用の文字配列 */
    FILE *fp;                  /* ファイルポインタ       */
    int x,y,col;               /* ループ変数             */

    if ( name[0] == '\0' ){
        printf("出力ファイル名 (拡張子はppm) : ");
        scanf("%s",fname);
    } else strcpy( fname, name );
    if ( (fp = fopen(fname, "wb"))==NULL ){
        printf("ファイルがオープンできませんでした\n");
        exit(1);  /* 強制終了 */
    }
    fputs( "P6\n", fp );  /* 識別子 */
    fputs( "# Created by Image Processing\n", fp );  /* コメント */
    fprintf( fp, "%d %d\n", width[n], height[n] );  /* サイズ */
    fprintf( fp, "%d\n", MAX_BRIGHTNESS );  /* 最大階調値 */
    /* 画像データの出力 */
    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            for(col=0;col<3;col++){
                fputc( image[n][x][y][col], fp );
            }
        }
    }
    fclose(fp);
    printf("画像は正常に出力されました．\n");
}


void copy_color_image( int n1, int n2 )
/* カラー画像No.n1をカラー画像No.n2にコピーする */
{
    int x,y,col;  /* 制御変数 */

    /* 横幅，縦幅の代入 */
    width[n2] = width[n1];  
    height[n2] = height[n1];
    /* 各色の階調データのコピー */
    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
            for(col=0;col<3;col++){
                image[n2][x][y][col] = image[n1][x][y][col];
            }
        }
    }
}


void init_color_image( int n, int red, int green, int blue )
/* カラー画像No.nの全画素の色を初期化 */
/* -1とした色は初期化対象外とする     */
{
    int x, y;  /* 制御変数 */

    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            if (red   != -1) image[n][x][y][0] = red;
            if (green != -1) image[n][x][y][1] = green;
            if (blue  != -1) image[n][x][y][2] = blue;
        }
    }
}
