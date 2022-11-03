#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

vector<vector<int>> A(N), B(N);
int a[N], parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    A[i].clear(), B[i].clear();
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

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  for(int i = 1; i <= n; ++i){
    A[Find(i)].push_back(i);
    B[Find(i)].push_back(a[i]);
  }

  for(int i = 1; i <= n; ++i){
    sort(B[i].begin(), B[i].end());
    for(int k = 0; k < A[i].size(); ++k){
      a[A[i][k]] = B[i][k];
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}