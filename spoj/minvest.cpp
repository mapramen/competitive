#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50000
#define M 1000

int dp[N];

int MaxProfit(int n, vector<pii>& a){
  n = n / M;
  for(int i = 0; i <= n; ++i){
    dp[i] = 0;
  }

  for(pii p: a){
    int x, c;
    tie(x, c) = p;
    x /= M;
    for(int i = x, j = 0; i <= n; ++i, ++j){
      dp[i] = max(dp[i], dp[j] + c);
    }
  }

  return dp[n];
}

int Solve(){
  int n, t, m;
  scanf("%d%d%d", &n, &t, &m);

  vector<pii> a(m);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }

  while(t--){
    n += MaxProfit(n, a);
  }

  return n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}