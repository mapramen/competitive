#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector< pii > > adj(N);
int a[N], u[N], ans[N];
bool visited[N];

void DFS(int i, int pEdge){
  visited[i] = 1;

  for(auto p : adj[i]){
    int edgeNo, k;
    tie(k, edgeNo) = p;
    if(visited[k]){
      continue;
    }
    DFS(k, edgeNo);
    a[i] += a[k];
  }

  ans[pEdge] = u[pEdge] != i ? a[i] : -a[i];
}

int main(){
  int n, m;

  scanf("%d", &n);

  int s = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    s += a[i];
  }

  if(s != 0){
    printf("Impossible\n");
    return 0;
  }

  scanf("%d", &m);
  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(MP(j, x));
    adj[j].PB(MP(i, x));
    u[x] = i;
  }

  DFS(1, 0);

  printf("Possible\n");
  for(int x = 1; x <= m; ++x)
    printf("%d\n", ans[x]);

  return 0;
}
