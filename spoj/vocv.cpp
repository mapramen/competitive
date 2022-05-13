#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100011
#define MOD 10007

vector<vector<int>> adj(N);
pii dp[2][N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    for(int x = 0; x < 2; ++x){
      dp[x][i] = {x, 1};
    }
  }
}

pii CombineAns(pii a, pii b){
  if(a.first < b.first){
    return a;
  }

  if(b.first < a.first){
    return b;
  }

  return {a.first, (a.second + b.second) % MOD};
}

pii AddAns(pii a, pii b){
  return {a.first + b.first, (a.second * b.second) % MOD};
}

void DFS(int i, int p){
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DFS(j, i);
    
    dp[0][i] = AddAns(dp[0][i], dp[1][j]);
    dp[1][i] = AddAns(dp[1][i], CombineAns(dp[0][j], dp[1][j]));
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  int ans, cnt;
  tie(ans, cnt) = CombineAns(dp[0][1], dp[1][1]);

  printf("%d %d\n", ans, cnt);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}