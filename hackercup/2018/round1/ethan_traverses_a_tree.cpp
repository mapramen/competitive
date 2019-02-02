#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

vector< vector<int> > adj(N);
int parent[N], ans[N];

int Find(int i){
  return (parent[i] == i) ? i : parent[i] = Find(parent[i]);
}

int Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return 0;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;

  return 1;
}

void DFS(int i, vector<int>& preOrderTraversal, vector<int>& postOrderTraversal){
  preOrderTraversal.PB(i);
  for(auto k : adj[i]){
    DFS(k, preOrderTraversal, postOrderTraversal);
  }
  postOrderTraversal.PB(i);
}

void Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    if(l){
      adj[i].PB(l);
    }
    if(r){
      adj[i].PB(r);
    }
  }

  vector<int> preOrderTraversal, postOrderTraversal;
  DFS(1, preOrderTraversal, postOrderTraversal);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  int maxLabels = n;
  for(int i = 0; i < n; ++i){
    maxLabels -= Union(preOrderTraversal[i], postOrderTraversal[i]);
  }

  if(maxLabels < m){
    printf(" Impossible\n");
  }
  else{
    for(int i = 1, k = 0; i <= n; ++i){
      int j = Find(i);
      if(j == i){
        ans[i] = k % m + 1;
        ++k;
      }
      else{
        ans[i] = ans[j];
      }
    }

    for(int i = 1; i <= n; ++i){
      printf(" %d", ans[i]);
    }
    printf("\n");
  }

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d:", k);
    Solve();
  }

  return 0;
}
