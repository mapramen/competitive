#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

int DFS(int i, int p){
  int cnt = adj[i].size() - (p != 0);
  if(cnt == 0){
    return 1;
  }

  if(cnt == 1){
    return 2;
  }

  int ans = N;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    ans = min(ans, DFS(j, i));
  }

  return 2 + ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);
  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  return n - DFS(1, 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}