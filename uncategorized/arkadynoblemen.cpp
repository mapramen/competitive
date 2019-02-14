#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair< int, ll >
#define PB push_back
#define MP make_pair
#define N 500001

vector< vector<int> > adj(N), v(N), c(N);
vector< vector< pil > > dAdj(N);
int listNo[N], inDegree[N];
ll ans[N];

void DFS(int i){
  int heavyChild = i;
  for(auto k : adj[i]){
    DFS(k);
    if(v[listNo[k]].size() > v[listNo[heavyChild]].size())
      heavyChild = k;
  }

  for(auto k : adj[i]){
    if(k == heavyChild)
      continue;
    Add
  }
}
int main(){


  return 0;
}
