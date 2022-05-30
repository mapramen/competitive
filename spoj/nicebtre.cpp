#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int DFS(string& s){
  if(s.empty()){
    return 0;
  }

  char c = s.back();
  s.pop_back();

  return c == 'l' ? 0 : 1 + max(DFS(s), DFS(s));
}

int Solve(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  return DFS(s);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}