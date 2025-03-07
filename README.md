## 実行
Mac(ARM64だけ?)+docker環境であれば、下記のXQuarZの設定をして
```
make build && make login
```

## DockerでのMacのminilibx環境再現について
結構苦労したので、同じことをしようとしている人がいたら

### 私の環境
```
❯ uname -a
Darwin nktr 22.6.0 Darwin Kernel Version 22.6.0: Wed Oct  4 21:25:40 PDT 2023; root:xnu-8796.141.3.701.17~4/RELEASE_ARM64_T8103 arm64
```

### 苦労したこと
- minilibx-linuxに`mlx_png_file_to_image`がない
  - `apt install imagemagic`して`convert`でxpmファイルにした後、`sed -i 's/png/xpm/g'`という回りくどいことをした
  - openglのminilibxはdockerで動かすのは難しそうだった

- XQuartZが連携してくれない。
  - XQuartZの設定から、「ネットワーク・クライアントからの接続を許可」にチェックをいれる
  - 毎回ビルドするのは面倒なので、`xclock`で確かめるのがよかった
  - shellを起動し直す時は、`xhost`コマンドから接続許可するように
  - 例: `IP=$(ifconfig en0 | grep inet | awk '$1=="inet" {print $2}'); xhost + $IP`

- キーが効かない
  - `xev`コマンドなどで試すと、入力自体は反応していることがわかった
  - MacとLinuxでkeycodeが違うことが原因 (例: escはMacだと`53`だけど、Linuxだと`65307`に対応)
