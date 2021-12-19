#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 1000000007

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  int ans = 0;
  while(m--){
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    ans |= x;
  }
  ans %= MOD;

  for(int i = 1; i < n; ++i){
    ans = (2 * ans) % MOD;
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