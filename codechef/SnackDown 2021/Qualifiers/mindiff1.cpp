#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);
int a[N], degree[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
    ++degree[i], ++degree[j];
  }

  for(int i = 1; i <= n; ++i){
    Q.push({degree[i], i});
  }

  int x = n;
  while(!Q.empty()){
    auto [di, i] = Q.top();
    Q.pop();

    if(di < 0 || degree[i] != di){
      continue;
    }

    degree[i] = -1;
    a[i] = x--;

    for(int j: adj[i]){
      --degree[j];
      Q.push({degree[j], j});
    }
  }

  int minD = INT_MAX, maxD = INT_MIN;
  for(int i = 1; i <= n; ++i){
    int d = 0;
    for(int j: adj[i]){
      d += (a[j] < a[i]);
    }
    minD = min(minD, d), maxD = max(maxD, d);

    degree[i] = 0;
    adj[i].clear();
  }

  printf("%d\n", maxD - minD);
  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}