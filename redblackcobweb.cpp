#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001
#define LOGN 17
#define MOD 1000000007

vector< vector<int> > edgeNoList(N);
int edgeEndXOR[N], edgeWeight[N], edgeColor[N], reds[N], blacks[N];
int products[N];
vector<int> T1, T2, D1, D2, C1, C2;
vector< vector< tiii > > V;

//------------------------------------- LCA -------------------------------------//
int start[N], finish[N], t_time[N], indx[N], ind = 1, timer = 1, LCA_Sparse_Table[LOGN + 1][2 * N], lg[2 * N];

void BuildLCASparseTable(int n){
  n = (n << 1);

  for(int i = 2; i < n; i++)
    lg[i] = 1 + lg[i / 2];

  for(int k = 1; (1 << k) < n; k++)
    for(int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; i++, j++)
      LCA_Sparse_Table[k][i] = min(LCA_Sparse_Table[k - 1][i], LCA_Sparse_Table[k - 1][j]);
}

int LCA(int x, int y){
  x = indx[x], y = indx[y];

  if(x > y) swap(x,y);

  int k = lg[y - x + 1];
  k = min(LCA_Sparse_Table[k][x], LCA_Sparse_Table[k][y - (1 << k) + 1]);
  int z = t_time[k];
  return z;
}
//----------------------------------- LCA Ends -----------------------------------//

//----------------------------------- Centroid Decomposition -----------------------------------//
vector< vector<int> > centroid_adj(N), centroid_subtree(N); //parent->child directed graph
int centroid_subtree_size[N], centroid_parent[N], tree_size = 0;
bool is_centroid[N];

void Centroid_Decomposition_DFS(int i, int p){
  centroid_subtree_size[i] = 1;
  for(auto edgeNo : edgeNoList[i]){
    int k = edgeEndXOR[edgeNo] ^ i;
    if(k != p && is_centroid[k] == 0){
      Centroid_Decomposition_DFS(k, i);
      centroid_subtree_size[i] += centroid_subtree_size[k];
    }
  }
}

int Centroid_Find_DFS(int i, int p){
  for(auto edgeNo : edgeNoList[i]){
    int k = edgeEndXOR[edgeNo] ^ i;
    if(k != p && is_centroid[k] == 0 && 2 * centroid_subtree_size[k] > tree_size)
      return Centroid_Find_DFS(k, i);
  }
  return i;
}

int Centroid_Decompose(int i, int p){
  Centroid_Decomposition_DFS(i,p);
  tree_size = centroid_subtree_size[i];

  i = Centroid_Find_DFS(i, p);
  is_centroid[i] = 1;

  for(auto edgeNo : edgeNoList[i]){
    int k = edgeEndXOR[edgeNo] ^ i;
    if(k != p && is_centroid[k] == 0){
      k = Centroid_Decompose(k, i);
      centroid_adj[i].PB(k);
      centroid_parent[k] = i;
    }
  }

  return i;
}

void Traverse_Centroid_Tree(int i){
  centroid_subtree[i].PB(i);
  for(auto k : centroid_adj[i]){
    Traverse_Centroid_Tree(k);
    for(auto j : centroid_subtree[k])
      centroid_subtree[i].PB(j);
  }
}
//--------------------------------- Centroid Decomposition Ends ---------------------------------//

int ModExp(int a, int n){
  int ans = 1;
  while(n){
    if(n % 2)
      ans = (1ll * ans * a) % MOD;
    a = (1ll * a * a) % MOD;
    n /= 2;
  }
  return ans;
}

int ModInverse(int a){
  return ModExp(a, MOD - 2);
}

void DFS(int i, int p){
  start[i] = timer;
  t_time[timer++] = i;
  indx[i] = ind;
  LCA_Sparse_Table[0][ind++] = start[i];

  for(auto edgeNo : edgeNoList[i]){
    int k = edgeEndXOR[edgeNo] ^ i;
    if(k == p)
      continue;
    products[k] = (1ll * products[i] * edgeWeight[edgeNo]) % MOD;
    reds[k] = reds[i] + 1 - edgeColor[edgeNo];
    blacks[k] = blacks[i] + edgeColor[edgeNo];
    DFS(k, i);
    LCA_Sparse_Table[0][ind++] = start[i];
  }

  finish[i] = timer;
}

int GetPathReds(int i, int j){
  int k = LCA(i, j);
  return (reds[i] - reds[k]) + (reds[j] - reds[k]);
}

int GetPathBlacks(int i, int j){
  int k = LCA(i, j);
  return (blacks[i] - blacks[k]) + (blacks[j] - blacks[k]);
}

int GetPathProduct(int i, int j){
  int k = LCA(i, j);
  int prod = (1ll * products[i] * products[j]) % MOD, invProd = ModInverse(products[k]);
  prod = (1ll * prod * invProd) % MOD;
  prod = (1ll * prod * invProd) % MOD;
  return prod;
}

tiii GetPathData(int i, int j){
  int k = LCA(i, j);
  int r = (reds[i] - reds[k]) + (reds[j] - reds[k]);
  int b = (blacks[i] - blacks[k]) + (blacks[j] - blacks[k]);
  int prod = (1ll * products[i] * products[j]) % MOD, invProd = ModInverse(products[k]);
  prod = (1ll * prod * invProd) % MOD;
  prod = (1ll * prod * invProd) % MOD;
  return MT(r, b, prod);
}

void Compress(vector<int>& C, vector<int>& T, vector<int>& D){
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  D.resize(C.size() + 1);
  for(int i = 0; i < D.size(); i++)
    D[i] = 0;

  T.resize(C.size() + 1);
  for(int i = 0; i < T.size(); i++)
    T[i] = 1;
}

int GetCompressedValue(vector<int>& C, int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin() + 1;
}

void AddUpdate(vector<int>& T, vector<int>& C, int i, int val){
  i = GetCompressedValue(C, i);
  for( ; i < T.size(); i += (i & -i))
    T[i] = (T[i] + val) % MOD;
}

int AddQuery(vector<int>& T, vector<int>& C, int i){
  i = GetCompressedValue(C, i);
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans = (ans + T[i]) % MOD;
  return ans;
}

void MulUpdate(vector<int>& T, vector<int>& C, int i, int val){
  i = GetCompressedValue(C, i);
  for( ; i < T.size(); i += (i & -i))
    T[i] = (1ll * T[i] * val) % MOD;
}

int MulQuery(vector<int>& T, vector<int>& C, int i){
  i = GetCompressedValue(C, i);
  int ans = 1;
  for( ; i > 0; i -= (i & -i))
    ans = (1ll * ans * T[i]) % MOD;
  return ans;
}

void Update(int v1, int v2, int val){
  MulUpdate(T1, C1, v1, val);
  MulUpdate(T2, C2, v2, val);
  AddUpdate(D1, C1, v1, 1);
  AddUpdate(D2, C2, v2, 1);
}

int main(){
  int n, ans = 1;

  scanf("%d", &n);
  for(int e = 1; e < n; e++){
    int i, j;
    scanf("%d%d%d%d", &i, &j, &edgeWeight[e], &edgeColor[e]);
    edgeNoList[i].PB(e);
    edgeNoList[j].PB(e);
    edgeEndXOR[e] = (i ^ j);
  }

  products[1] = 1;
  DFS(1, 0);
  BuildLCASparseTable(n);

  int centroid_root = Centroid_Decompose(1, 0);
  Traverse_Centroid_Tree(centroid_root);

  for(int i = 1; i <= n; i++){
    C1.clear();
    C2.clear();
    V.clear();

    for(auto k : centroid_adj[i]){
      vector< tiii > U;
      for(auto j : centroid_subtree[k]){
        int r, b, prod;
        tie(r, b, prod) = GetPathData(i, j);
        int v1 = 2 * r - b, v2 = 2 * b - r;
        C1.PB(v1), C1.PB(-v1);
        C2.PB(v2), C2.PB(-v2);
        U.PB(MT(v1, v2, prod));
      }
      V.PB(U);
    }

    Compress(C1, T1, D1);
    Compress(C2, T2, D2);

    Update(0, 0, 1);
    int product = 1, invproduct = 1, total = 1;

    for(auto U : V){
      for(auto t : U){
        int v1, v2, prod;
        tie(v1, v2, prod) = t;

        int x = AddQuery(D1, C1, v1) + AddQuery(D2, C2, v2) - total;

        if(x){
          int ansx = (1ll * MulQuery(T1, C1, v1) * MulQuery(T2, C2, v2)) % MOD;
          ansx = (1ll * ansx * invproduct) % MOD;
          ansx = (1ll * ansx * ModExp(prod, x)) % MOD;
          ans = (1ll * ansx * ans) % MOD;
        }
      }

      for(auto t : U){
        int v1, v2, prod;
        tie(v1, v2, prod) = t;
        v1 = -v1, v2 = -v2;
        Update(v1, v2, prod);
        total++;
        product = (1ll * prod * product) % MOD;
      }
      invproduct = ModInverse(product);
    }
  }

  printf("%d\n", ans);

  return 0;
}
