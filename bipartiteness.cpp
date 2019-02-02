#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int d[N], parent[N], odd, even;

void DFS(int i){
  d[i] = 1 + d[parent[i]];
  odd += (d[i] % 2);
  even += (1 - d[i] % 2);

  for(auto k : adj[i]){
    if(k == parent[i])
      continue;
    parent[k] = i;
    DFS(k);
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);

  ll ans = 1ll * odd * even - n + 1;

  printf("%lld\n", ans);

  return 0;
}
