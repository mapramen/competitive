#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int c[N], subtreeSize[N], heapNo[N];
priority_queue<int> Q[N];

ll DFS(int i){
  int heavyChild = i;
  ll ans = 0;

  for(auto k : adj[i]){
    ans += DFS(k);
    if(subtreeSize[k] > subtreeSize[heavyChild]){
      heavyChild = k;
    }
  }

  heapNo[i] = heapNo[heavyChild];
  int y = heapNo[i];

  subtreeSize[i] = 1;
  for(auto k : adj[i]){
    subtreeSize[i] += subtreeSize[k];
    if(k == heavyChild){
      continue;
    }
    int x = heapNo[k];
    while(!Q[x].empty()){
      Q[y].push(Q[x].top());
      Q[x].pop();
    }
  }

  Q[y].push(i);

  while(c[i] > 0 && !Q[y].empty()){
    ans += Q[y].top();
    Q[y].pop();
    --c[i];
  }

  return ans;
}

ll Solve(){
  int n, m, a, b;

  scanf("%d%d%d%d", &n, &m, &a, &b);

  for(int i = 0; i < N; ++i){
    adj[i].clear();
    subtreeSize[i] = 0;
    c[i] = 0;
    heapNo[i] = i;
    while(!Q[i].empty()){
      Q[i].pop();
    }
  }

  for(int j = 1; j < n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].PB(j);
  }

  for(int i = 0, x = b % n; i < m; ++i, x = (x + a) % n){
    ++c[x];
  }

  return DFS(0);
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }

  return 0;
}
