/* カラー画像処理用ヘッダファイル ppmlib.h */


/* 定数宣言 */
// 645 × 380
// #define MAX_IMAGESIZE   3000 /* 想定する縦・横の最大画素数    */
#define MAX_IMAGESIZE_H   380 /* 想定する縦の最大画素数    */
#define MAX_IMAGESIZE_W   645 /* 想定する横の最大画素数    */

#define MAX_BRIGHTNESS   255 /* 想定する最大階調値            */
#define GRAYLEVEL        256 /* 想定する階調数(=最大階調値+1) */
#define MAX_FILENAME     256 /* 想定するファイル名の最大長    */
#define MAX_BUFFERSIZE   256 /* 利用するバッファ最大長        */
#define MAX_NUM_OF_IMAGES  3 /* 利用する画像の枚数            */

/* 大域変数の宣言 */
/* 画像データ image[n][x][y][col] (col=0:R, =1:G, =2:B) */
unsigned char image[MAX_NUM_OF_IMAGES]
    [MAX_IMAGESIZE_H][MAX_IMAGESIZE_W][3];
/* 横幅と縦幅 */
int width[MAX_NUM_OF_IMAGES],height[MAX_NUM_OF_IMAGES];

/* 関数のプロトタイプ宣言 */
void load_color_image( int n, char name[] ); /* 画像の入力   */
void save_color_image( int n, char name[] ); /* 画像の出力   */
void copy_color_image( int n1, int n2 );     /* 画像のコピー */
void init_color_image( int n, int red, int green, int blue );
                                             /* 画像の初期化 */
