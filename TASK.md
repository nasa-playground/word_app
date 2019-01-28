## プログラムの機能に関する説明
英単語のクイズを出すプログラムを作成

問題はファイルから読み込む。 en:jaのような形式しか受け付けていないのでイケてない。

yamlとかtomlとかで定義したかったけど時間が、、、、

## 格納するデータに関する説明
英語をkey、日本語をvalueとしてmapを作る
そして、そのmapのvectorを作る

## 使用するコンテナの選択理由
英語と日本語で対応しているのでmapを使用した。
全てのmapリストが欲しかったのでvectorを使用した。
配列でいいと思ったがvectorのほうが扱いやすそうだったのでvectorにしました。

indexアクセス(言葉が正しいかわかりませんが)を用いてないのでlistコンテナでもいいかと思いました。

## コンテナへのデータ格納方法に関する説明
英語をkey、日本語をvalueとしてmapを作る

ファイルを読み込んでmapに格納した。

## プログラムの機能を実現するためにコンテナに格納されるデータに対して必要な処理に関する説明
読み込んた文字列をkeyとvalueに分けるために':'を基準に分割した

## クラス図およびその説明
Dictionaryクラスを導入した。

mapをメンバ変数として持つだけのクラス。

文字列から初期化するコンストラクタを持つ、そして、ユーザー入力を受け取り答えがあっているか判定し結果を表示する処理を持つ。

このプログラム場合クラスを用いないほうがシンプルな処理になると思う。

## 変数表
メンバ変数dict
dict: map<string, string>型を格納するためのメンバ変数

## コンテナ格納されてオブジェクトの処理に使用した関数やアルゴリズム、関数オブジェクトの説明
コンストラクタsplit関数を使用している。 これは区切り文字を受け取りその文字の前と後で文字列を分割し、vectorに格納して返す関数である。

ループでぶん回して区切り文字を探している。

## シーケンス図およびプログラム実行時のオブジェクト間のメッセージと処理の流れに関する説明

## 実行画面のスクリーンショットおよびプログラムのコンパイル方法及び実行方法
clang++でコンパイルした

./a.outのように実行した

以下のコマンド
clang++ main.cpp
./a.out

## プログラムリスト
```
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef string Ja;
typedef string En;
typedef map<Ja,En> Dict;
typedef vector<Dict> Dicts;

vector<std::string> split(const std::string &str, char sep);
map<string, string> analyze_file(string str);

// 無理やり導入したクラス
// mapをメンバ変数として持つだけ
class Dictionary {
public:
  Dict dict;

  // StringからDictを作る
  Dictionary(string str) {
    vector<string> v = split(str, ':');

    En en = v[0];
    Ja ja = v[1];

    dict[en] = ja;
  }

  // 正解かどうかチェックする
  void answer() {
    for(auto itr = dict.begin(); itr != dict.end(); ++itr) {
      cout << itr->second<< "の英語は？";

      string answer;
      cin >>  answer;

      if(answer == itr->first)
        cout << "正解\n";
      else
        cout << "不正解\n";
    }
  }
};

int main(int argc,char *argv[]) {
  string filename = argv[1];

  std::ifstream ifs(filename);
  std::string str;
  if (ifs.fail()) {
    std::cerr << "Failed: load file" << std::endl;
    return -1;
  }

  vector<Dictionary> dicts;
  while (getline(ifs, str)) {
    dicts.push_back(Dictionary(str));
  }

  for(auto dict = dicts.rbegin(); dict != dicts.rend(); ++dict) {
    dict->answer();
  }

  cout << "おつおつ!\n";
}

// stringにsplitがないらしいので作成
vector<std::string> split(const std::string &str, char sep) {
    std::vector<std::string> v;
    auto first = str.begin();
    while( first != str.end() ) {
        auto last = first;
        while( last != str.end() && *last != sep )
            ++last;
        v.push_back(std::string(first, last));
        if( last != str.end() )
            ++last;
        first = last;
    }
    return v;
}
```

## プログラムの作成時に発生した技術的な問題点と解決方法
なし

## プログラムの作成にあたり協力関係にあった学生の学籍番号と氏名
なし

## プログラム作成時間
30分 ~ 1時間

## レポート作成時間
2時間
