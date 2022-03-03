#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define N 101

vector<vector<pli>> adj(N);
ll d[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void CheckAndPush(int i, ll di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int main(){
  int n, s, m;
  ll T;

  scanf("%d%d%lld%d", &n, &s, &T, &m);

  while(m--){
    int i, j;
    ll w;
    scanf("%d%d%lld", &i, &j, &w);
    adj[j].push_back({w, i});
  }

  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  CheckAndPush(s, 0);

  while(!Q.empty()){
    int i;
    ll di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pli& p: adj[i]){
      CheckAndPush(p.second, di + p.first);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (d[i] <= T);
  }

  printf("%d\n", ans);
  
  return 0;
}