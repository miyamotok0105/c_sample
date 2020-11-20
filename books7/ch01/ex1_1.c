#include <stdio.h>
#include <stdlib.h>
#include "wave.h"

int main(void)
{
  MONO_PCM pcm0, pcm1;
  int n;
  
  mono_wave_read(&pcm0, "a.wav"); /* WAVEファイルからモノラルの音データを入力する */
  
  pcm1.fs = pcm0.fs; /* 標本化周波数 */
  printf("Sampling frequency %d \n", pcm0.fs);
  pcm1.bits = pcm0.bits; /* 量子化精度 */
  printf("Quantization accuracy %d \n", pcm0.bits);
  pcm1.length = pcm0.length; /* 音データの長さ */
  printf("Length %d \n", pcm0.length);
  pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */
  for (n = 0; n < pcm1.length; n++)
  {
    pcm1.s[n] = pcm0.s[n]; /* 音データのコピー */
  }
  
  mono_wave_write(&pcm1, "b.wav"); /* WAVEファイルにモノラルの音データを出力する */
  
  /* メモリの解放 */
  free(pcm0.s);
  free(pcm1.s);
  
  return 0;
}
