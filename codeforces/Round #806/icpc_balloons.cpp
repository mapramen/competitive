#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  string s;
  cin >> n >> s;
  int mask = 0;
  for(char c: s){
    mask |= (1 << (c - 'a'));
  }
  return s.size() + __builtin_popcount(mask);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}