#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N);
vector< pii > updates[N];
int d[N];
ll T[N], ans[N];

void Update(int i, int val){
  for( ; i < N; i += (i & -i)){
    T[i] += val;
  }
}

ll Query(int i){
  ll ans = 0;
  for(i = min(i, N - 1); i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void DFS(int i, int p){
  d[i] = 1 + d[p];

  for(auto update : updates[i]){
    int x, val;
    tie(x, val) = update;
    Update(d[i], val);
    Update(d[i] + x + 1, -val);
  }

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  ans[i] = Query(d[i]);

  for(auto update : updates[i]){
    int x, val;
    tie(x, val) = update;
    Update(d[i], -val);
    Update(d[i] + x + 1, val);
  }
}

int main(){
  int n, q;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  scanf("%d", &q);
  while(q--){
    int i, x, val;
    scanf("%d%d%d", &i, &x, &val);
    updates[i].PB(MP(x, val));
  }

  DFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%lld ", ans[i]);
  }
  printf("\n");

  return 0;
}
