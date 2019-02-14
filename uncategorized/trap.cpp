#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 50001
#define M 150001
#define K 196
#define B 8
#define MOD (1 << B)
#define FILTER_MASK (MOD - 1)

vector< vector<int> > adj(N);
int n, a[N], parent[N], skipParent[N], d[N], h[N], path[N], T[2][1 + B * MOD], C[2][1 + B * MOD], S[K][N], R[MOD][N], nextNode;

void Update(int x, int val){
  int i = 0;
  for(int k = B - 1; k > -1; --k){
    int j = ((x & (1 << k)) > 0);
    if(T[j][i] == 0)
      T[j][i] = ++nextNode;
    C[j][i] += val;
    i = T[j][i];
  }
}

int Query(int x){
  int i = 0, ans = 0;
  for(int k = B - 1; k > -1; --k){
    int j = 1 - ((x & (1 << k)) > 0);
    if(C[j][i] > 0)
      ans |= (1 << k), i = T[j][i];
    else
      i = T[1 - j][i];
  }
  return ans;
}

void DFS(int i){
  d[i] = 1 + d[parent[i]];
  path[d[i]] = i;

  Update((a[i] >> B), 1);

  if(d[i] > MOD)
    Update((a[path[d[i] - MOD]] >> B), -1);

  for(auto k : adj[i]){
    if(k == parent[i])
      continue;
    parent[k] = i;
    DFS(k);
    h[i] = max(h[i], 1 + h[k]);
  }

  for(int k = 0, x = 0; x <= h[i]; ++k, x += MOD)
    S[k][i] = Query(k);

  for(int j = 0, k = i; j < MOD && k != 0; ++j, k = parent[k]){
    int x = (a[k] >> B);
    R[x][i] = max(R[x][i], (a[k] & FILTER_MASK) ^ (j));
    skipParent[i] = k;
  }

  Update((a[i] >> B), -1);

  if(d[i] > MOD)
    Update((a[path[d[i] - MOD]] >> B), 1);
}

int Query(int i, int j){
  int k = j, ans = 0;
  while(d[skipParent[k]] >= d[i]){
    int x = ((d[j] - d[k]) >> B);
    int y = S[x][k];
    ans = max(ans, (y << B) + R[(x ^ y)][k]);
    k = parent[skipParent[k]];
  }
  while(d[k] >= d[i]){
    ans = max(ans, (a[k] ^ (d[j] - d[k])));
    k = parent[k];
  }
  return ans;
}

int main(){
  int q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);

  while(q--){
    int i, j, ans = 0;
    scanf("%d%d", &i, &j);
    printf("%d\n", Query(i, j));
  }

  return 0;
}
