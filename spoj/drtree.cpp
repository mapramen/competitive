#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 17

char op[2];
vector<vector<int>> adj(N);
int a[N], d[N], T[LOGN + 1][N];
ll dp[N];

void PreProcess(int n){
  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }
}

int KthAncestor(int k, int i){
  for(int x = LOGN; x > -1; --x){
    if((k & (1 << x))){
      i = T[x][i];
      k ^= (1 << x);
    }
  }
  return i;
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  j = KthAncestor(d[j] - d[i], j);

  if(i == j){
    return i;
  }

  for(int k = LOGN; k > -1; --k){
    if(T[k][i] != T[k][j]){
      i = T[k][i], j = T[k][j];
    }
  }

  return T[0][i];
}

void DFS(int i){
  dp[i] = a[i];
  for(int j: adj[i]){
    T[0][j] = i;
    d[j] = 1 + d[i];
    DFS(j);
    dp[i] += dp[j];
  }
}

ll Query(int root, int i){
  if(root == i){
    return dp[1];
  }

  int lca = LCA(root, i);

  if(lca != i){
    return dp[i];
  }

  return dp[1] - dp[KthAncestor(d[root] - d[i] - 1, root)];
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].push_back(j);
  }

  int root = 1;
  DFS(root);
  PreProcess(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int i;
    scanf("%s%d", op, &i);

    if(op[0] == 'R'){
      root = i;
    }
    else{
      printf("%lld\n", Query(root, i));
    }
  }
  
  return 0;
}