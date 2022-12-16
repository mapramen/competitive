#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

set<string> S;

void Reset(){
  S.clear();
}

void Add(string& s){
  if(s.empty()){
    return;
  }

  S.insert(s);
  s.clear();
}

int Solve(){
  Reset();
  for(string s; true; ){
    char c;

    if(scanf("%c", &c) == EOF || c == '\n'){
      Add(s);
      break;
    }

    if(isalpha(c)){
      s.push_back(c);
      continue;
    }

    Add(s);
  }
  return S.size();
}

int main(){
  int t;
  scanf("%d", &t);
  getchar();
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}