#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiiii tuple<int,int,int,int,int>

map<int,set<int>> adj, arrayIndex;

int Parent(int n){
  int p = 1;
  for( ; p < n; p <<= 1);

  return p - n;
}

void AddToSet(map<int,set<int>>& S, int i, int j){
  auto it = S.find(i);
  if(it != S.end()){
    it->second.insert(j);
  }
  else{
    S[i] = {j};
  }
}

tiiiii DFS(int p){
  int len = INT_MIN, i = -1, j = -1;
  int h, ih;

  auto sit = arrayIndex.find(p);
  if(sit == arrayIndex.end()){
    h = INT_MIN, ih = -1;
  }
  else{
    set<int>& s = sit->second;
    
    h = 0, ih = *s.begin();

    if(s.size() > 1){
      len = 0, i = *s.begin(), j = *s.rbegin();
    }
  }

  for(int x: adj[p]){
    auto [lenx, ix, jx, hx, ihx] = DFS(x);
    
    tie(len, i, j) = max(make_tuple(len, i, j), make_tuple(lenx, ix, jx));
    tie(len, i, j) = max(make_tuple(len, i, j), make_tuple(h + 1 + hx, ih, ihx));

    tie(h, ih) = max(make_tuple(h, ih), make_tuple(1 + hx, ihx));
  }

  return {len, i, j, h, ih};
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    AddToSet(arrayIndex, x, i);

    for(int p = 0; x != 0; x = p){
      p = Parent(x);
      AddToSet(adj, p, x);
    }
  }

  auto [len, i, j, h, ih] = DFS(0);
  printf("%d %d %d\n", i, j, len);

  return 0;
}