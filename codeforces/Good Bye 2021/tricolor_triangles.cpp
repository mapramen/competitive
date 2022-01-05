#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define M 256

pii edges[M];
int edgeColor[M];

vector<tiii> GetTriangles(int n, int m){
  map<pii,int> S;
  for(int e = 0; e < m; ++e){
    auto [u, v] = edges[e];
    if(v < u){
      swap(u, v);
    }
    S[{u, v}] = e;
  }

  vector<tiii> triangles;

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      for(int k = j + 1; k <= n; ++k){
        auto it = S.find({i, j});
        auto jt = S.find({j, k});
        auto kt = S.find({i, k});

        if(it != S.end() && jt != S.end() && kt != S.end()){
          triangles.push_back({it->second, jt->second, kt->second});
        }
      }
    }
  }

  return triangles;
}

void SwapColumns(vector<int>& p, vector<vector<int>>& A, int c1, int c2){
  if(c1 == c2){
    return;
  }

  for(int i = A.size() - 1; i != -1; --i){
    swap(A[i][c1], A[i][c2]);
  }
  swap(p[c1], p[c2]);
}

bool GaussElimination(int n, vector<tiii>& triangles){  
  vector<vector<int>> A;

  for(int e = 0; e < n; ++e){
    if(edgeColor[e] == -1){
      continue;
    }

    vector<int> a(n + 1);
    a[e] = 1, a[n] = (edgeColor[e]) % 3;

    A.push_back(a);
  }

  for(auto [e1, e2, e3]: triangles){
    vector<int> a(n + 1);
    a[e1] = 1, a[e2] = 1, a[e3] = 1;

    A.push_back(a);
  }

  vector<int> p(n);
  for(int e = 0; e < n; ++e){
    p[e] = e;
  }

  int i = 0;
  while(i < A.size()){
    bool isRowZero = true;
    for(int k = i; k < n && isRowZero; ++k){
      isRowZero = A[i][k] == 0;
    }

    if(isRowZero){
      if(A[i][n] != 0){
        return false;
      }

      int m = A.size();
      swap(A[i], A[m - 1]);
      A.pop_back();
      continue;
    }

    int c1 = i, c2 = i;
    for( ; A[i][c2] == 0; ++c2);
    SwapColumns(p, A, c1, c2);

    vector<int>& ai = A[i];

    if(ai[i] == 2){
      for(int k = i, x = ai[i]; k <= n; ++k){
        ai[k] = (x * ai[k]) % 3;
      }
    }

    for(int j = A.size() - 1; j != -1; --j){
      if(j == i || A[j][i] == 0){
        continue;
      }

      vector<int>& aj = A[j];
      for(int k = i, x = aj[i]; k <= n; ++k){
        aj[k] = (6 + aj[k] - x * ai[k]) % 3;
      }
    }

    ++i;
  }

  for(int i = A.size() - 1; i != -1; --i){
    edgeColor[p[i]] = A[i][n];
  }

  for(int e = 0; e < n; ++e){
    if(edgeColor[e] <= 0){
      edgeColor[e] = 3;
    }
  }

  return true;
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < m; ++x){
    scanf("%d%d%d", &edges[x].first, &edges[x].second, &edgeColor[x]);
  }

  vector<tiii> triangles = GetTriangles(n, m);

  if(!GaussElimination(m, triangles)){
    printf("-1\n");
    return;
  }

  for(int e = 0; e < m; ++e){
    printf("%d ", edgeColor[e]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}