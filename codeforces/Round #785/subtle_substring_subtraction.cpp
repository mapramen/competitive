#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetCost(char c){
  return c - 'a' + 1;
}

void Solve(){
  string s;
  cin >> s;

  int ans = 0;
  for(char c: s){
    ans += GetCost(c);
  }

  if(s.size() % 2 == 1){
    ans -= 2 * GetCost(min(s.front(), s.back()));
  }

  printf("%s %d\n", ans > 0 ? "Alice" : "Bob", abs(ans));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}