#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int dp[N][2][2];

void DFS(int i, int p){
  int pIndex = 0;
  for(int j = 0; j < adj[i].size(); ++j){
    int k = adj[i][j];
    if(k == p){
      pIndex = j;
      continue;
    }
    DFS(k, i);
  }

  if(p){
    adj[i].erase(adj[i].begin() + pIndex);
  }

  int x, y;

  x = 0, y = adj[i].size() > 0 ? N : 1;
  for(auto k : adj[i]){
    int z = min(dp[k][0][0], dp[k][0][1]);
    x += z;
    y = min(y, dp[k][0][1] - z);
  }
  dp[i][0][0] = x + y;
  dp[i][1][0] = x;

  x = (p > 1);
  for(auto k : adj[i]){
    x += min(dp[k][1][0], dp[k][1][1]);
  }
  dp[i][0][1] = x;
  dp[i][1][1] = x;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0);

  int ans = min(min(dp[1][0][0], dp[1][0][1]), min(dp[1][1][0], dp[1][1][1]));
  printf("%d\n", ans);

  return 0;
}
