#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

pll a[N];
ll dp[2][N], inf = 1E18;

bool Check(int n, ll k){
  int cur = 0;

  for(int x = 0; x < N; ++x){
    dp[cur][x] = -inf;
  }

  dp[cur][0] = 0;
  for(int i = 1; i <= n; ++i, cur = 1 - cur){
    int j, nxt = 1 - cur;
    vector<ll> c(1);

    for(j = i; j <= n && a[j].first == a[i].first; i = j, ++j){
      c.PB(k * a[j].second - 1000 * a[j].first);
    }

    sort(c.begin() + 1, c.end(), greater<ll>());

    for(int y = 0; y < N; ++y)
      dp[nxt][y] = -inf;

    int m = c.size() - 1;
    ll s = 0;
    j = 0;
    for(auto sx : c){
      s += sx;
      for(int x = m - j; x < N; ++x){
        int y = x + j - (m - j);
        if(y < 0 || y >= N){
          continue;
        }
        dp[nxt][y] = max(dp[nxt][y], dp[cur][x] + s);
      }
      ++j;
    }
  }

  ll ans = -inf;
  for(int x = 0; x < N; ++x){
    ans = max(ans, dp[cur][x]);
  }

  return (ans >= 0);
}

ll BinarySearch(int n){
  ll x = 0, y = 1E13, z = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(n, mid)){
      z = mid, y = mid - 1;
    }
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i].first;

  for(int i = 1; i <= n; ++i)
    cin >> a[i].second;

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  cout << BinarySearch(n) << '\n';

  return 0;
}
