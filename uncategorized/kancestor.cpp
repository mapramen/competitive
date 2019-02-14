#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N), v(N);
int k, a[N], ans[N];

void DFS(int i, int p){
  v[a[i]].PB(i);
  for(auto j : adj[i]){
    if(j == p)
      continue;
    DFS(j, i);
  }

  v[a[i]].pop_back();

  if(v[a[i]].size() >= k)
    ans[i] = v[a[i]][v[a[i]].size() - k];
  else
    ans[i] = -1;
}

int main(){
  int n;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0);

  for(int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
