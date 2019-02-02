#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N);
int parent[N], a[N], g = N;
bool marked[N];

void DFS(int i){
  a[i] = min(i, a[parent[i]]);
  for(auto k : adj[i]){
    if(k == parent[i])
      continue;
    parent[k] = i;
    DFS(k);
  }
}

void Update(int i){
  for( ; marked[i] == 0; i = parent[i]){
    g = min(g, i);
    marked[i] = 1;
  }
}

int main(){
  int n, q, ans = 0;
  marked[0] = 1;
  a[0] = N;

  scanf("%d%d", &n, &q);
  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  while(q--){
    int t, i;
    scanf("%d%d", &t, &i);
    i = (i + ans) % n + 1;

    if(g == N)
      DFS(i);

    if(t == 1 && g != 1)
      Update(i);

    if(t == 2){
      ans = min(a[i], g);
      printf("%d\n", ans);
    }
  }

  return 0;
}
