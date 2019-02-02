#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

vector< vector<int> > adj(N);
int n, a[N], c[N], dp[N];
ll S = 0;

ll DFS(int i){
  ll s = a[i];
  for(auto j : adj[i]){
    s += DFS(j);
  }
  ll k = S / __gcd(S, s);
  if(k <= n){
    ++c[k];
  }
  return s;
}

int main(){
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    S += a[i];
  }

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].PB(j);
  }

  DFS(1);

  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; j += i){
      dp[j] += c[i];
    }
    dp[i] = (i == dp[i]);
  }

  for(int i = n; i > 0; --i){
    if(dp[i] == 0){
      continue;
    }
    ll val = 0;
    for(int j = i; j <= n; j += i){
      val = (val + dp[j]) % MOD;
    }
    dp[i] = val;
  }

  printf("%d\n", dp[1]);

  return 0;
}
