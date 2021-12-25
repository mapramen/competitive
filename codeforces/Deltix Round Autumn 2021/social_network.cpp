#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int parent[N], sz[N];
vector<int> v;

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

int Query(int n, int x){
  for(int i = 1; i <= n; ++i){
    if(parent[i] == i){
      v.push_back(sz[i]);
      x -= (sz[i] - 1);
    }
  }

  sort(v.begin(), v.end());

  int ans = 0;
  for(++x; x != 0; --x){
    ans += v.back();
    v.pop_back();
  }

  v.clear();
  return ans - 1;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    sz[i] = 1;
  }

  for(int x = 1; x <= q; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
    printf("%d\n", Query(n, x));
  }

  return 0;
}