#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define MOD 1000000007

int a[N], b[N], parent[N], sz[N];
bool marked[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1, marked[i] = false;
  }
}

int Find(int i){
  return parent[i] == i ? parent[i] : parent[i] = Find(parent[i]);
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
  marked[i] = marked[i] || marked[j];
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    marked[x] = true;
  }

  for(int i = 1; i <= n; ++i){
    Union(a[i], b[i]);
  }

  int ans = 1;
  for(int i = 1; i <= n; ++i){
    if(Find(i) == i && sz[i] != 1 && !marked[i]){
      ans = (2 * ans) % MOD;
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