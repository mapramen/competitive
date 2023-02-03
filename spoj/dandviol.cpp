#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 401

int parent[N], sz[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
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
  sz[i] += sz[j];
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }

  Reset(2 * n);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  for(pii& p: a){
    p.first = Find(p.first);
    p.second = Find(p.second);

    if(p.first > p.second){
      swap(p.first, p.second);
    }
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int ans = 0;
  for(pii& p: a){
    int i, j;
    tie(i, j) = p;

    if(i == j){
      continue;
    }

    ans += sz[i] * sz[j];
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}