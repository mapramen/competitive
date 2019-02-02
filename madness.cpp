#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

vector< vector< pii > > adj(N);
int parent[N], parentEdge[N];
double T[N];

void DFS(int i){
  double x = 2, t = T[i];
  x /= adj[i].size();

  while(t >= 2)
    t -= 2;

  T[i] = t;

  if(t >= 1)
    t -= 1;
  else
    t = 1 + t;

  for(auto p : adj[i]){
    int k, e;
    tie(k, e) = p;
    if(k == parent[i])
      continue;

    parent[k] = i;
    parentEdge[k] = e;
    t += x;
    T[k] = t;

    DFS(k);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(MP(j, x));
    adj[j].PB(MP(i, x));
  }

  DFS(1);

  printf("%d\n", n - 1);
  for(int i = 2; i <= n; i++){
    int v = parent[i], u = i, e = parentEdge[i];
    double t = T[i];

    if(t >= 1){
      t = 2 - t;
      swap(u, v);
    }
    else
      t = 1 - t;

    printf("1 %d %d %d %.9lf\n", e, u, v, t);
  }

  return 0;
}
