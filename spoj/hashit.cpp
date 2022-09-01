#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 101

char s[MOD];
string T[MOD];

int GetHash(string s){
  int ans = 0;
  for(int i = 0; i < s.size(); ++i){
    ans = (ans + 19 * (i + 1) * s[i]) % MOD;
  }

  for(int j = 0; j < 20; ++j){
    int i = (ans + j * j + 23 * j) % MOD;
    if(T[i].empty()){
      return i;
    }
  }

  return -1;
}

void Delete(string s){
  for(int i = 0; i < MOD; ++i){
    if(T[i] == s){
      T[i].clear();
    }
  }
}

void Add(string s){
  for(int i = 0; i < MOD; ++i){
    if(s == T[i]){
      return;
    }
  }

  int i = GetHash(s);
  if(i == -1){
    return;
  }
  
  T[i] = s;
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < MOD; ++i){
    T[i].clear();
  }

  while(n--){
    scanf("%s", s);

    string key = string(s + 4);
    if(s[0] == 'A'){
      Add(key);
    }
    else{
      Delete(key);
    }
  }

  int ans = 0;
  for(int i = 0; i < MOD; ++i){
    ans += !T[i].empty();
  }

  printf("%d\n", ans);
  for(int i = 0; i < MOD; ++i){
    if(!T[i].empty()){
      printf("%d:%s\n", i, T[i].c_str());
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}