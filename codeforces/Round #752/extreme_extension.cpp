#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define MOD 998244353

int a[N];
vector<pii> dp, t;

int Ceil(int x, int y){
  return (x + y - 1) / max(1, y);
}

int Floor(int x, int y){
  return x / max(1, y);
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;

  dp.push_back({0, 0});
  for(int i = 1; i <= n; ++i){
    reverse(dp.begin(), dp.end());

    int k = 1;
    while(k <= a[i]){
      int x = Floor(a[i], k);
      int kx = Ceil(a[i - 1], x);

      while(!dp.empty() && dp.back().first < kx){
        dp.pop_back();
      }

      int ansx = (dp.back().second + 1ll * (k - 1) * i) % MOD;
      t.push_back({k, ansx});

      if(k == a[i]){
        break;
      }
      k = Ceil(a[i], Ceil(a[i], k) - 1);
    }

    dp.clear();
    dp.swap(t);

    ans = (ans + dp.front().second) % MOD;
  }

  dp.clear();
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