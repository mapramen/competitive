#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N);
int k, ans = 1;

int DFS(int i, int p = 0){
  if(adj[i].size() == 1){
    return 0;
  }

  vector<int> v;
  for(auto k : adj[i]){
    if(k == p){
      continue;
    }
    v.PB(1 + DFS(k, i));
  }

  sort(v.begin(), v.end());

  while(v.size() > 1 && (v.back() + v[v.size() - 2] > k)){
    ++ans;
    v.pop_back();
  }

  return v.back();
}

int main(){
  int n;

  scanf("%d%d", &n, &k);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  int root = 0;
  for(root = 1; adj[root].size() == 1; ++root);

  DFS(root);

  printf("%d\n", ans);

  return 0;
}
