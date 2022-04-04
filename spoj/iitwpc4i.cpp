#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<pii>> adj(N);
int d[N];
bool marked[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void CheckAndPush(int i, int di){
  if(!marked[i] && di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

string Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
    marked[i] = false;
    adj[i].clear();
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(x == 1){
      CheckAndPush(i, 0);
    }
  }

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    marked[i] = true;
    for(pii& p: adj[i]){
      CheckAndPush(p.first, p.second);
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    if(!marked[i]){
      return "impossible";
    }
    ans += d[i];
  }

  return to_string(ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}