#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 50001
#define B 10

int m;
vector< vector<int> > adj(N);
int a[N], g[(1 << B)], c[N][(1 << B)], t[(1 << B)];
ll ans = 0;

void ORT(int P[], bool inverse){
  for(int len = 1, n = (1 << m); len < n; len = (len << 1)){
    for(int i = 0; i < n; i += (len + len)){
      for(int j = 0; j < len; ++j){
        int u = P[i + j], v = P[i + len + j];
        if(!inverse){
          P[i + j] = u + v;
          P[i + len + j] = u;
        }
        else{
          P[i + j] = v;
          P[i + len + j] = u - v;
        }
      }
    }
  }
}

void DFS(int i, int p){
  c[i][a[i]]++;
  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
    ORT(c[i], false);
    ORT(c[k], false);
    for(int x = 0; x < (1 << m); ++x)
      t[x] = c[i][x] * c[k][x];
    ORT(t, true);
    ORT(c[i], true);
    ORT(c[k], true);
    for(int x = 0; x < (1 << m); ++x){
      c[i][(x | a[i])] += c[k][x];
      ans += t[x] * g[x];
    }
  }
}

int main(){
  int n;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    --a[i];
    a[i] = (1 << a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int x = 0; x < (1 << m); ++x){
    for( ; (x & (1 << g[x])) != 0; ++g[x]);
    ++g[x];
  }

  DFS(1, 0);

  printf("%lld\n", ans);

  return 0;
}
