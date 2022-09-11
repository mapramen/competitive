#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> reverse_adj(N);
int out_degree[N], d[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void CheckAndPush(int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    reverse_adj[j].push_back(i);
    ++out_degree[i];
  }

  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
  }

  CheckAndPush(n, 0);

  while(!Q.empty()){
    auto [di, i] = Q.top();
    Q.pop();

    if(d[i] != di){
      continue;
    }

    for(int j: reverse_adj[i]){
      CheckAndPush(j, di + out_degree[j]);
      --out_degree[j];
    }
  }

  printf("%d\n", d[1]);
  
  return 0;
}