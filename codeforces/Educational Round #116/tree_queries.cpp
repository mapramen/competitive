#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N), dp(N);
int c[N], s[N];

void UpdateDP(vector<int>& dpParent, vector<int>& dpChild){
  for(int k = dpChild.size() - 1; k != -1; --k){
    dpParent[k] += max(1, dpChild[k] - k);
  }
}

void DFS(int i, int p){
  c[i] = adj[i].size() - (p != 0);
  int m = c[i] + 1;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    m = max(m, (int)dp[j].size());
  }

  dp[i].resize(m + 1);
  
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    UpdateDP(dp[i], dp[j]);
    ++s[dp[j].size()];
  }

  for(int k = 0, x = 0; k <= m; ++k){
    x += s[k];
    dp[i][k] += x;
    s[k] = 0;
  }

  while(!dp[i].empty()){
    int k = dp[i].size() - 1;
    if(dp[i][k] == c[i] && dp[i][k] - k <= 1){
      dp[i].pop_back();
    }
    else{
      break;
    }
  }
}

int Query(int i, int k){
  return k >= dp[i].size() ? c[i] : dp[i][k];
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  int q;
  scanf("%d", &q);

  while(q--){
    int i, k;
    scanf("%d%d", &i, &k);
    printf("%d\n", Query(i, k));
  }

  return 0;
}