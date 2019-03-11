#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 40

ll adjMask[N];
map< string, int > stringMap;
vector<int> v;

int GetStringIndex(string s){
  if(stringMap.count(s)){
    return stringMap[s];
  }
  else{
    int k = stringMap.size();
    stringMap[s] = k;
    return k;
  }
}

void AddEdges(){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i : v){
    for(int j : v){
      adjMask[i] |= (1ll << j);
    }
  }

  v.clear();
}

int ChoosePivotVertex(ll P){
  P &= -P;
  return __builtin_popcountll(P - 1);
}

int BronKerbosch(ll R, ll P){
  if(P == 0){
    return __builtin_popcountll(R);
  }

  int u = ChoosePivotVertex(P);

  int ans = 0;
  for(ll Px = (P ^ (P & adjMask[u])); Px; ){
    int v = ChoosePivotVertex(Px);
    ans = max(ans, BronKerbosch(R | (1ll << v), P & adjMask[v]));
    P ^= (P & (1ll << v));
    Px ^= (Px & (1ll << v));
  }

  return ans;
}

int main(){
  int n, q;

  scanf("%d%d", &q, &n);

  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      AddEdges();
    }
    else{
      string s;
      cin >> s;
      v.push_back(GetStringIndex(s));
    }
  }

  AddEdges();

  ll allVertexMask = (1ll << n) - 1;
  for(int i = 0; i < n; ++i){
    adjMask[i] |= (1ll << i);
    adjMask[i] ^= allVertexMask;
  }

  int ans = BronKerbosch(0ll, allVertexMask);

  printf("%d\n", ans);

  return 0;
}