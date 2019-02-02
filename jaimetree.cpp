#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17

vector< vector<int> > adj(N);
int a[N], d[N], start[N], finish[N], T[LOGN][N], timer;
ll T1[N], T2[N];

void DFS(int i, int p){
  start[i] = ++timer;
  T[0][i] = p;
  d[i] = 1 + d[p];

  for(auto k : adj[i]){
    if(k != p)
      DFS(k, i);
  }

  finish[i] = timer;
}

int LCA(int u, int v){
  if(d[u] > d[v])
    swap(u, v);

  for(int k = LOGN - 1; k > -1 && d[v] > d[u]; --k){
    if(d[v] - d[u] >= (1 << k))
      v = T[k][v];
  }

  for(int k = LOGN - 1; k > -1; --k){
    if(T[k][u] != T[k][v])
      u = T[k][u], v = T[k][v];
  }

  if(u != v)
    u = T[0][u];

  return u;
}

int KthAncestor(int i, int v){
  for(int k = LOGN - 1; k > -1; --k){
    if((1 << k) <= i){
      i -= (1 << k);
      v = T[k][v];
    }
  }
  return v;
}

bool IsAncestor(int u, int v){
  return (start[u] <= start[v] && finish[v] <= finish[u]);
}

void Update(ll T[], int i, ll x){
  for( ; i < N; i += (i & -i))
    T[i] += x;
}

void Update(int i, int j, int x){
  Update(T1, i, -1ll * (i - 1) * x);
  Update(T1, j + 1, 1ll * j * x);
  Update(T2, i, x);
  Update(T2, j + 1, -x);
}

void SubtreeUpdate(int i, int x){
  Update(start[i], finish[i], x);
}

void NodeUpdate(int i, int x){
  Update(T1, start[i], x);
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

ll Query(int i){
  ll a = Query(T2, i), b = Query(T1, i);
  return a * i + b;
}

ll Query(int i, int j){
  return Query(j) - Query(i - 1);
}

ll SubtreeQuery(int i){
  return Query(start[i], finish[i]);
}

void PreProcess(int n){
  DFS(1, 0);

  for(int k = 1; k < LOGN; ++k)
    for(int i = 1; i <= n; ++i)
      T[k][i] = T[k - 1][T[k - 1][i]];

  for(int i = 1; i <= n; ++i)
    NodeUpdate(i, a[i]);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  PreProcess(n);

  int root = 1;

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      scanf("%d", &root);
    }
    else if(t == 2){
      int i, j, k, x;
      scanf("%d%d%d", &i, &j, &x);
      k = LCA(i, j);

      if(k != root && !IsAncestor(k, root)){
        SubtreeUpdate(k, x);
      }
      else{
        SubtreeUpdate(1, x);
        if(IsAncestor(root, i) || IsAncestor(root, j)){
          //
        }
        else{
          if(IsAncestor(i, root)){
            SubtreeUpdate(KthAncestor(d[root] - d[i] - 1, root), -x);
          }
          else if(IsAncestor(j, root)){
            SubtreeUpdate(KthAncestor(d[root] - d[j] - 1, root), -x);
          }
          else{
            int ik = LCA(i, root), jk = LCA(j, root);
            if(ik != k){
              SubtreeUpdate(KthAncestor(d[root] - d[ik] - 1, root), -x);
            }
            else if(jk != k){
              SubtreeUpdate(KthAncestor(d[root] - d[jk] - 1, root), -x);
            }
            else{
              SubtreeUpdate(KthAncestor(d[root] - d[k] - 1, root), -x);
            }
          }
        }
      }
    }
    else{
      int v;
      scanf("%d", &v);

      if(v == root){
        printf("%lld\n", SubtreeQuery(1));
      }
      else if(!IsAncestor(v, root)){
        printf("%lld\n", SubtreeQuery(v));
      }
      else{
        printf("%lld\n", SubtreeQuery(1) - SubtreeQuery(KthAncestor(d[root] - d[v] - 1, root)));
      }
    }
  }

  return 0;
}
