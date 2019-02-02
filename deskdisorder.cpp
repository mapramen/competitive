#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

int parent[N], sz[N];
bool isCycle[N], isLoop[N];

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

void Union(int i, int j){
  if(i == j){
    i = Find(i);
    isCycle[i] = 1;
    isLoop[i] = 1;
  }
  else{
    i = Find(i), j = Find(j);
    if(i == j)
      isCycle[i] = 1;
    else{
      if(i > j)
        swap(i, j);
      parent[j] = i;
      sz[i] += sz[j];
      isCycle[i] |= isCycle[j];
      isLoop[i] |= isLoop[j];
    }
  }
}

int main(){
  int n;
  ll ans = 1;

  scanf("%d", &n);

  for(int i = 1; i <= 2 * n; ++i){
    parent[i] = i;
    sz[i] = 1;
  }

  for(int x = 1; x <= n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  for(int i = 1; i <= 2 * n; ++i){
    if(i != parent[i] || isLoop[i] == 1)
      continue;

    if(isCycle[i])
      ans = (ans * 2) % MOD;
    else
      ans = (ans * sz[i]) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
