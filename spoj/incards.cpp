#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define N 1000001

vector<vector<pii>> adj(N), reverse_adj(N);
ll d[N];
priority_queue<pli,vector<pli>,greater<pli>> Q;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear(), reverse_adj[i].clear();
  }
}

void CheckAndPush(int i, ll val){
  if(val < d[i]){
    d[i] = val;
    Q.push({val, i});
  }
}

ll Dijkstra(int n, vector<vector<pii>>& adj){
  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  CheckAndPush(1, 0);

  while(!Q.empty()){
    int i;
    ll di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pii& edge: adj[i]){
      CheckAndPush(edge.first, di + edge.second);
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += d[i];
  }

  return ans;
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    reverse_adj[j].push_back({i, w});
  }

  return Dijkstra(n, adj) + Dijkstra(n, reverse_adj);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}