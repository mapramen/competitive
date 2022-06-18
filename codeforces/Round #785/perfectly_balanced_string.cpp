#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;

  set<char> S;
  for(char c: s){
    S.insert(c);
  }

  int n = s.size(), m = S.size();
  for(int i = m; i < n; ++i){
    if(s[i] != s[i - m]){
      return false;
    }
  }

  S.clear();
  for(int i = 0; i < m; ++i){
    S.insert(s[i]);
  }

  return S.size() == m;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}