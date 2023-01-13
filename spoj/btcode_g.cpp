#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int parent[N], color[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

void Color(int i, int x){
  color[i] = x;
  for(int j: adj[i]){
    if(color[j] == x){
      Union(i, j);
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;

    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  Reset(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int t, i, j;
    scanf("%d%d%d", &t, &i, &j);
    
    if(t == 1){
      ++i;
      Color(i, j);
    }
    else{
      ++i, ++j;
      printf("%s\n", Find(i) == Find(j) ? "YES" : "NO");
    }
  }

  return 0;
}