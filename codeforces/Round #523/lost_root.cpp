#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

char temp[4];
vector<int> treeSizes, subtreeSize;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool Query(int a, int b, int c){
  printf("? %d %d %d\n", a, b, c);
  fflush(stdout);
  scanf("%s", temp);
  return temp[0] == 'Y';
}

void PrintAns(int root){
  printf("! %d\n", root);
  fflush(stdout);
}

void Initialise(int n, int k){
  for(ll s = 1, p = k; s < n; s += p, p *= k){
    treeSizes.PB(s);
  }
  treeSizes.PB(n);
  subtreeSize.resize(n + 1);
}

pii GetRandomNodePair(int n){
  int u = uniform_int_distribution<int>(1, n)(rng), v = u;
  for( ; v == u; v = uniform_int_distribution<int>(1, n)(rng));
  return MP(u, v);
}

int DepthFromTreeSize(int s){
  return lower_bound(treeSizes.begin(), treeSizes.end(), s) - treeSizes.begin();
}

int FindRoot(vector<int> v, int u, int d){
  for(auto i : v){
    int c = 0;
    for(auto j : v){
      c += Query(u, j, i);
    }
    if(c == d + 1){
      return i;
    }
  }
}

int main(){
  int n, k, d;

  scanf("%d%d", &n, &k);

  Initialise(n, k);
  d = DepthFromTreeSize(n);

  while(true){
    int u, v;

    tie(u, v) = GetRandomNodePair(n);
    subtreeSize[u] = 1, subtreeSize[v] = 1;
    vector<int> roots{u, v};

    for(int i = 1; i <= n; ++i){
      if(i == u || i == v){
        continue;
      }
      if(Query(i, u, v)){
        ++subtreeSize[u];
      }
      else if(Query(i, v, u)){
        ++subtreeSize[v];
      }
      else if(Query(u, i, v)){
        roots.PB(i);
      }
    }

    int du = DepthFromTreeSize(subtreeSize[u]), dv = DepthFromTreeSize(subtreeSize[v]);

    if(du + dv + roots.size() - 1 != 2 * d){
      continue;
    }

    PrintAns(FindRoot(roots, u, d - du));
    break;
  }

  return 0;
}
