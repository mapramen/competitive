#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int max_depth[N], max_path_length[N];

void DFS(int i, int p){
  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    DFS(j, i);

    max_path_length[i] = max(max(max_path_length[i], max_path_length[j]), max_depth[i] + 1 + max_depth[j]);
    max_depth[i] = max(max_depth[i], 1 + max_depth[j]);
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  int r;
  scanf("%d", &r);

  DFS(r, 0);

  int q;
  scanf("%d", &q);

  while(q--){
    int i;
    scanf("%d", &i);
    printf("%d\n", max_path_length[i]);
  }

  return 0;
}