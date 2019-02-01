#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int parent[N];
bool valid[N];

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    if(valid[i]){
      valid[i] = 0;
      return 1;
    }
    return 0;
  }
  else{
    if(valid[i] || valid[j]){
      if(i > j)
        swap(i, j);
      parent[j] = i;
      valid[i] = (valid[i] & valid[j]);
      return 1;
    }
    return 0;
  }
}

int main(){
  int n, m, ans = 0;
  vector< piii > v;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    v.PB(MP(k, MP(i, j)));
  }

  sort(v.begin(), v.end(), greater< piii >());

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    valid[i] = 1;
  }

  for(auto p : v){
    int i, j, k;
    k = p.first;
    tie(i, j) = p.second;
    if(Union(i, j))
      ans += k;
  }

  printf("%d\n", ans);

  return 0;
}
