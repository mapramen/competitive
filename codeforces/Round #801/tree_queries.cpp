#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

int DFS(int i, int p){
  int ans = 0, cnt = 0;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    int ansx = DFS(j, i);
    
    ans += ansx;
    cnt += (ansx == 0);
  }
  return ans + max(0, cnt - 1);
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

  if(n <= 2){
    return n - 1;
  }

  int root = 1;
  for( ; root <= n && adj[root].size() < 3; ++root);

  if(root > n){
    return 1;
  }

  return DFS(root, 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}