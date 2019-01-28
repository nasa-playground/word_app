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

int main(int argc,char *argv[]) {
  string filename = argv[1];
  cout << filename;

  // input file
  std::ifstream ifs(filename);
  std::string str;
  if (ifs.fail()) {
    std::cerr << "Failed: load file" << std::endl;
    return -1;
  }

  Dicts dicts;
  while (getline(ifs, str)) {
    dicts.push_back(analyze_file(str));
  }

  for(auto dict = dicts.rbegin(); dict != dicts.rend(); ++dict) {
    for(auto itr = dict->begin(); itr != dict->end(); ++itr) {
      cout << itr->second<< "の英語は？";

      string answer;
      cin >>  answer;

      if(answer == itr->first)
        cout << "正解\n";
      else
        cout << "不正解\n";
    }
  }

  cout << "おつおつ!\n";
}

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

map<string, string> analyze_file(string str) {
  vector<string> v = split(str, ':');

  En en = v[0];
  Ja ja = v[1];

  Dict dict;

  dict[en] = ja;

  return dict;
}
