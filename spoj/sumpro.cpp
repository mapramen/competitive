#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    i = n / (n / i);
    v.push_back({i, n / i});
  }
  reverse(v.begin(), v.end());

  int l = 1, ans = 0;
  for(pii& p: v){
    int x = p.first, r = p.second;
    int m = r - l + 1;
    
    int ansx = (1ll * m * (l + r) / 2) % MOD;
    ansx = (1ll * ansx * x) % MOD;

    ans = (ans + ansx) % MOD;
    l = r + 1;
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