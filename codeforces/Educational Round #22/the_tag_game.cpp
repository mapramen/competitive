#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int d1[N], d2[N], ans = 0;

void DFS1(int i, int p){
  for(auto k : adj[i]){
    if(k == p)
      continue;
    d1[k] = d1[i] + 1;
    DFS1(k, i);
  }
}

void DFS2(int i, int p){
  ans = max(ans, 2 * d1[i]);
  if(d2[i] >= d1[i])
    return ;
  for(auto k : adj[i]){
    if(k == p)
      continue;
    d2[k] = d2[i] + 1;
    DFS2(k, i);
  }
}

int main(){
  int n, x;

  scanf("%d%d", &n, &x);

  for(int k = 1; k < n; k++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS1(1, 0);
  DFS2(x, 0);

  printf("%d\n", ans);

  return 0;
}
