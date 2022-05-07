#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetMaxFrequency(int n){
  map<int,int> C;

  while(n--){
    int x;
    scanf("%d", &x);
    ++C[x];
  }

  int ans = 0;
  for(auto [_, c]: C){
    ans = max(ans, c);
  }

  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  int m = GetMaxFrequency(n);

  int ans = 0;
  while(m < n){
    ans += (1 + min(m, n - m));
    m = min(n, 2 * m);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}