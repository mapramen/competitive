#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N), v(N);
int d[N], h[N], heavyChild[N], c[N], dominantIndices[N], ans;

void HeavyChildDFS(int i, int p){
  d[i] = 1 + d[p];
  int k = i;
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    HeavyChildDFS(j, i);
    if(h[j] > h[k]){
      k = j;
    }
  }
  h[i] = 1 + h[k];
  heavyChild[i] = k;
}

void ResetBag(int i){
  ans = 0;
  for(int x = d[i], y = d[i] + h[i]; x < y; ++x){
    v[i].PB(c[x]);
    c[x] = 0;
  }
}

void TransferBag(int i){
  for(int x = 0, k = d[i]; x < v[i].size(); ++x, ++k){
    c[k] += v[i][x];
    if(c[k] > c[ans]){
      ans = k;
    }
    if(c[k] == c[ans] && k < ans){
      ans = k;
    }
  }
  v[i].clear();
}

void DFS(int i, int p){
  for(auto j : adj[i]){
    if(j == p || j == heavyChild[i]){
      continue;
    }
    DFS(j, i);
    ResetBag(j);
  }

  if(heavyChild[i] != i){
    DFS(heavyChild[i], i);
  }

  v[i].PB(1);
  TransferBag(i);
  v[i].clear();

  for(auto j : adj[i]){
    if(j == p || j == heavyChild[i]){
      continue;
    }
    TransferBag(j);
  }

  dominantIndices[i] = ans - d[i];
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

  HeavyChildDFS(1, 0);
  DFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d\n", dominantIndices[i]);
  }

  return 0;
}
