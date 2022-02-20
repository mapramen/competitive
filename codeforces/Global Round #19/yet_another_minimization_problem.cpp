#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  return a;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a = ReadArray(n);
  vector<int> b = ReadArray(n);

  int m = 100 * n, s = 0;
  vector<bool> dp(m + 1);

  dp[0] = true;
  for(int i = 0; i < n; ++i){
    int x = a[i], y = b[i];
    vector<bool> t(m + 1);
    for(int k = m; k > 0; --k){
      if(k >= x){
        t[k] = t[k] || dp[k - x];
      }

      if(k >= y){
        t[k] = t[k] || dp[k - y];
      }
    }
    swap(dp, t);
    s += (x + y);
  }

  int ans = INT_MAX;
  for(int k = 0; k <= m; ++k){
    if(!dp[k]){
      continue;
    }
    int sa = k, sb = s - sa;
    ans = min(ans, sa * sa + sb * sb);
  }

  for(int x: a){
    ans += (n - 2) * x * x;
  }

  for(int y: b){
    ans += (n - 2) * y * y;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}