#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 27

vector< vector< pii > > adj(N);
int w[N], d[N], parentEdge[N];
vector< int > bases;

int GetResidue(int x){
  int k = B - 1;
  for(auto y : bases){
    for( ; k > -1 && (y & (1 << k)) == 0; --k);
    if(k > -1 && (x & (1 << k)) > 0)
      x ^= y;
  }
  return x;
}

void InsertBase(int x){
  x = GetResidue(x);

  if(x == 0)
    return ;

  bases.PB(x);
  sort(bases.begin(), bases.end(), greater<int>());

  int k = B - 1;
  for(int i = 0; i < bases.size(); ++i){
    int x = bases[i];
    for( ; k > -1 && (x & (1 << k)) == 0; --k);
    for(int j = i + 1; k > -1 && j < bases.size(); ++j){
      if((bases[j] & (1 << k)) > 0)
        bases[j] ^= x;
    }
  }
}

void DFS(int i){
  for(auto p : adj[i]){
    int k, e;
    tie(k, e) = p;
    if(e == parentEdge[i])
      continue;
    if(parentEdge[k]){
      int x = (d[k] ^ d[i] ^ w[e]);
      x = GetResidue(x);
      InsertBase(x);
    }
    else{
      d[k] = d[i] ^ w[e];
      parentEdge[k] = e;
      DFS(k);
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int e = 1; e <= m; ++e){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    if(i != j){
      adj[i].PB(MP(j, e));
      adj[j].PB(MP(i, e));
      w[e] = k;
    }
    else
      InsertBase(k);
  }

  DFS(1);

  printf("%d\n", GetResidue(d[1] ^ d[n]));

  return 0;
}
