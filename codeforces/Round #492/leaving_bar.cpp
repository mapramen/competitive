#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int x[N], y[N], ans[N], nxt;
vector<int> v;

void MergeVectors(){
  if(v.size() < 2){
    return ;
  }
  
  int ansi = 0, ansj = 0, anski = 1, anskj, s = 0;
  ll ansd = LLONG_MAX;
  ++nxt;

  for(auto i : v){
    for(auto j : v){
      if(i >= j){
        continue;
      }
      for(int kj = -1; kj < 2; kj += 2){
        int a = x[i] + kj * x[j];
        int b = y[i] + kj * y[j];
        ll d = 1ll * a * a + 1ll * b * b;
        if(d < ansd){
          ansd = d;
          ansi = i, ansj = j, anskj = kj;
          x[nxt] = a, y[nxt] = b;
        }
      }
    }
    s += i;
  }

  adj[nxt].PB(ansi);
  adj[nxt].PB(ansj);
  ans[ansi] = anski;
  ans[ansj] = anskj;
  s -= (ansi + ansj);

  v.clear();
  if(s){
    v.PB(s);
  }
  v.PB(nxt);
}

void DFS(int i){
  for(auto k : adj[i]){
    ans[k] *= ans[i];
    DFS(k);
  }
}

int main(){
  int n;

  scanf("%d", &n);
  nxt = n;

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &y[i]);
    v.PB(i);
    ans[i] = 1;
    if(v.size() > 2){
      MergeVectors();
    }
  }

  MergeVectors();

  ans[nxt] = 1;
  DFS(nxt);

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}
