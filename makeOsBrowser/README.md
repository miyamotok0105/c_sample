
WEB/DB pressの内容「自作OS、自作ブラウザ」を勉強。
[元のソース](https://github.com/hikalium/liumos/blob/master/app/ping/ping.c)


```
コンパイル
gcc ping.c lib.c
IPアドレスを探す
dig google.com
ping実行
./a.out 192.168.100.1
```


# 参考

[ping](https://github.com/hikalium/liumos/blob/master/app/ping/ping.c)
[ping lib](https://github.com/hikalium/liumos/blob/master/app/liumlib/liumlib.h)
[ping lib](https://github.com/hikalium/liumos/blob/master/app/liumlib/liumlib.c)

[mkファイル](https://hikalium.hatenablog.jp/entry/2019/12/19/231440)
[mkファイルはMakefile以外のファイルでmakeできる](http://objectclub.jp/community/memorial/homepage3.nifty.com/masarl/article/gnu-make/getting-started.html)

