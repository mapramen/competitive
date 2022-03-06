#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000
#define BLOCK_SIZE 500

bitset<N> T;
map<int,vector<int>> indexMap;
map<int,bitset<N>> bitsetMap;
vector<vector<int>> A;

void UnionBitset(int x, bitset<N>& t){
  auto it = bitsetMap.find(x);
  if(it != bitsetMap.end()){
    t |= it->second;
    return;
  }

  for(int i: indexMap[x]){
    t.set(i);
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  A = vector<vector<int>>(n, vector<int>(m + 1));
  for(vector<int>& a: A){
    for(int j = 0; j <= m; ++j){
      scanf("%d", &a[j]);
    }
    swap(a[0], a[m]);
  }
  sort(A.begin(), A.end());

  for(int i = 0; i < n; ++i){
    for(int j = 1; j <= m; ++j){
      indexMap[A[i][j]].push_back(i);
    }
  }
  
  for(auto &[x, v]: indexMap){
    if(v.size() < BLOCK_SIZE){
      continue;
    }

    bitset<N> t;
    for(int i: v){
      t.set(i);
    }

    bitsetMap[x] = t;
  }

  int ans = INT_MAX;
  for(int i = 0; i < n; ++i){
    T.reset();
    for(int j = 1; j <= m; ++j){
      UnionBitset(A[i][j], T);
    }

    int k = T.flip()._Find_first();
    if(k < i){
      ans = min(ans, A[k][0] + A[i][0]);
    }
  }

  if(ans == INT_MAX){
    ans = -1;
  }

  printf("%d\n", ans);

  return 0;
}