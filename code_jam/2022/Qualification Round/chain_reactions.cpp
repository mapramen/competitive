#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int fun[N], max_fun[N];

int Calculate(int i){
  int ans = adj[i].empty() ? 0 : INT_MAX;
  for(int j: adj[i]){
    ans = min(ans, max_fun[j]);
  }
  max_fun[i] = max(fun[i], ans);
  return max(0, fun[i] - ans);
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &fun[i]);
  }

  for(int i = 1; i <= n; ++i){
    int p;
    scanf("%d", &p);
    adj[p].push_back(i);
  }

  ll ans = 0;
  for(int i = n; i != -1; --i){
    ans += Calculate(i);
  }

  for(int i = 0; i <= n; ++i){
    adj[i].clear();
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}