#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int boss[N];
bool visited[N];
vector<int> topological_order;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    visited[i] = false;
  }
  topological_order.clear();
}

void DFS(int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  for(int j: adj[i]){
    DFS(j);
  }

  topological_order.push_back(i);
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= k; ++i){
    int w;
    scanf("%d", &w);

    while(w--){
      int j;
      scanf("%d", &j);
      adj[i].push_back(j);
    }
  }

  for(int i = 1; i <= n; ++i){
    DFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  int direct_boss = 0;
  for(int i: topological_order){
    boss[i] = direct_boss;
    direct_boss = i;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d\n", boss[i]);
  }
  
  return 0;
}