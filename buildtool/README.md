
# C言語のビルド周りのツール

```
brew install autoconf automake libtool
```

## make

```
cd make1
make
./main
```

$(CC)の前はタブである必要あり。mainって名前のバイナリを出力。

```
all: ans.o main.o
	$(CC) $^ -o main
```

## configure


```
autoscan
mv configure.scan configure.ac

```


# 参考

メリットデメリットが書かれてて纏まってる。

https://qiita.com/turenar/items/922a845cfc9350b0eece#fn1
