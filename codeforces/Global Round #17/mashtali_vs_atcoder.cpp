#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);
int parent[N], grundy[N];
bool grounded[N];

int DFS(int i, int p){
  int g = 0;
  vector<int> v;

  parent[i] = p;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    v.push_back(j);
    g ^= (1 + DFS(j, i));
  }

  adj[i] = v;
  grundy[i] = g;

  return g;
}

void Ground(int k){
  if(grounded[k]){
    return;
  }

  vector<int> v;
  for(int i = k; i != 1; i = parent[i]){
    v.push_back(i);
  }

  int g = grundy[1] ^ (1 + grundy[v.back()]);

  for(int i: v){
    for(int j: adj[i]){
      parent[j] = 1;
      g ^= (1 + grundy[j]);
    }

    adj[i].clear();
    grundy[i] = 0;
    grounded[i] = true;
  }

  grundy[1] = g ^ 1;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  grounded[1] = true;

  for(int i = 1; i <= n; ++i){
    Ground(i);
    putchar('1' + (grundy[1] == 0));
  }
  putchar('\n');

  return 0;
}