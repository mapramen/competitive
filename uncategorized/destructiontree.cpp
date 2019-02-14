#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector<int> v[4];
vector< vector<int> > adj(N);
vector< pii > ans[N][2];
bool dp[N][2];

void Transfer(vector<int>& v, int x, vector< pii >& ans, bool skipLast = 0){
  for(int i = 0; i < v.size() - skipLast; ++i)
    ans.PB(MP(v[i], x));
}

void DFS(int i, int p){
  if(adj[i].size() == 0 || (adj[i].size() == 1 && p != 0)){
    dp[i][0] = 1;
    ans[i][0].PB(MP(i, 0));
    return ;
  }

  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
  }

  for(int j = 0; j < 4; ++j)
    v[j].clear();

  for(auto k : adj[i]){
    if(k == p){
      continue;
    }
    int j = dp[k][0] + 2 * dp[k][1];
    v[j].PB(k);
  }

  if(v[0].size()){
    return ;
  }

  for(int x = 0; x < 2; ++x){
    if(v[1].size() % 2 == x || v[3].size() > 0){
      dp[i][x] = 1;
      Transfer(v[2], 1, ans[i][x]);
      Transfer(v[3], 1, ans[i][x], v[1].size() % 2 == 1 - x);
      ans[i][x].PB(MP(i, 0));
      if(v[1].size() % 2 == 1 - x){
        ans[i][x].PB(MP(v[3].back(), 0));
      }
      Transfer(v[1], 0, ans[i][x]);
    }
  }
}

void Print(int i, int x){
  for(auto p : ans[i][x]){
    int k, j;
    tie(k, j) = p;
    if(k == i){
      printf("%d\n", i);
    }
    else{
      Print(k, j);
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    if(j == 0)
      continue;
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0);

  if(dp[1][0]){
    printf("YES\n");
    Print(1, 0);
  }
  else{
    printf("NO\n");
  }

  return 0;
}
