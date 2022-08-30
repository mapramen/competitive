#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 27

char raw_string[B];
map<string,int> C;
map<ll,pii> M;
vector<string> words;

string ReadString(){
  scanf("%s", raw_string);
  return string(raw_string);
}

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    ++C[ReadString()];
  }

  for(pair<string,int> p: C){
    string s = p.first;
    int i = words.size(), cnt = p.second;

    words.push_back(s);

    ll hsh = 0;
    for(char c: s){
      hsh = hsh * B + (c - 'a' + 1);
      M[hsh] = min(M[hsh], {-cnt, i});
    }
  }

  int q;
  scanf("%d", &q);

  while(q--){
    string s = ReadString();

    ll hsh = 0;
    for(char c: s){
      hsh = hsh * B + (c - 'a' + 1);
    }

    auto it = M.find(hsh);
    if(it == M.end()){
      printf("-1\n");
    }
    else{
      printf("%s %d\n", words[it->second.second].c_str(), -it->second.first);
    }
  }
  
  return 0;
}