#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define LOGN 18
#define M 1001

int a[N], d[N], lca[1 + LOGN][N];
bitset<M> dp[1 + LOGN][N], ans;

void PreProcess(int n){
  for(int i = n; i != -1; --i){
    dp[0][i].set(a[lca[0][i]]);
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      int j = lca[k - 1][i];
      lca[k][i] = lca[k - 1][j];
      dp[k][i] = dp[k - 1][i] | dp[k - 1][j];
    }
  }
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  for(int x = d[j] - d[i], k = LOGN; k != -1; --k){
    if((x & (1 << k)) == 0){
      continue;
    }
    j = lca[k][j];
  }

  if(i == j){
    return i;
  }

  for(int k = LOGN; k > -1; --k){
    if(lca[k][i] == lca[k][j]){
      continue;
    }
    i = lca[k][i], j = lca[k][j];
  }

  return lca[0][i];
}

void CollectAns(int j, int i){
  ans.set(a[j]);

  for(int x = d[j] - d[i], k = LOGN; k != -1; --k){
    if((x & (1 << k)) == 0){
      continue;
    }
    ans |= dp[k][j];
    j = lca[k][j];
  }
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  d[1] = 1;
  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    ++p;
    d[i] = 1 + d[p];
    lca[0][i] = p;
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  while(q--){
    ans.reset();
    for(int x = 0; x < 3; ++x){
      int i, j;
      scanf("%d%d", &i, &j);
      ++i, ++j;

      int k = LCA(i, j);
      CollectAns(i, k), CollectAns(j, k);
    }
    printf("%lu\n", ans.count());
  }

  return 0;
}