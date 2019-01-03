
## 通常実行


```
gcc main.c
./a.out
```

## 分割

extern(エクスターン)修飾子でグローバル変数扱いへ。    
extern int ans;この記述。    


```
gcc main2.c sub.c sub2.c
./a.out
```


## コンパイラの流れ


.cファイル + .hファイル　→　「プリプロセッサ」
「コンパイラ」　→　objファイル + libファイル　→　リンカ　→　実行ファイル
