#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int c[N], parent[N];

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i > j)
    swap(i, j);
  parent[j] = i;
  c[i] = min(c[i], c[j]);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
    parent[i] = i;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    if(i == parent[i])
      ans += c[i];
  }

  printf("%lld\n", ans);

  return 0;
}
