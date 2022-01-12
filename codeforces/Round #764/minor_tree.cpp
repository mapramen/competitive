#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 200001

int parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
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

bool Check(int n, int m, vector<tiii>& edges){
  Reset(n);

  for(auto [i, j, w]: edges){
    if((m | w) <= m){
      Union(i, j);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(Find(i) != 1){
      return false;
    }
  }

  return true;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<tiii> edges;
  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    edges.push_back({i, j, w});
  }

  int ans = 0;
  for(int k = 30; k != -1; --k){
    if(!Check(n, ans + (1 << k) - 1, edges)){
      ans |= (1 << k);
    }
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