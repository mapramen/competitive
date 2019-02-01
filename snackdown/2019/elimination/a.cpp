#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

int M[N][N];
vector<int> adj[N * N], d[N * N], v[N * N][N];

bool BFS(int n, int s, vector<int>& d){
  d.clear();
  d.resize(n + 1);

  for(int i = 1; i <= n; ++i){
    d[i] = n;
  }

  for(int i = 0; i < N; ++i){
    v[s][i].clear();
  }

  queue<int> Q;
  Q.push(s);
  d[s] = 0;

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    v[s][d[i]].PB(i);
    for(auto j : adj[i]){
      if(d[j] > 1 + d[i]){
        d[j] = 1 + d[i];
        Q.push(j);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    if(d[i] >= n){
      return 0;
    }
  }

  for(int i = 0; i < N; ++i){
    sort(v[s][i].begin(), v[s][i].end());
  }

  return 1;
}

void FlipMatrixVerticalAxis(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; 2 * j <= n; ++j){
      swap(M[i][j], M[i][n - j + 1]);
    }
  }
}

void RotateMatrixBy90CW(int n){
  for(int i = 1, j = n; i <= j; ++i, --j){
    for(int k = 0; i + k < j; ++k){
      swap(M[i][i + k], M[i + k][j]);
      swap(M[i][i + k], M[j][j - k]);
      swap(M[i][i + k], M[j - k][i]);
    }
  }
}

void FillOneQuadrantLeftHalf(int n){
  int a = M[n][1], b = M[n][n], c = M[1][1];
  for(int j = 2; 2 * j <= n + 1; ++j){
    vector<int> u;
    set_intersection(v[a][j - 1].begin(), v[a][j - 1].end(), v[b][n - j].begin(), v[b][n - j].end(), back_inserter(u));
    for(auto x : u){
      M[d[c][x] + 1][j] = x;
    }
  }
}

void FillOneQuadrant(int n){
  for(int c = 0; c < 2; ++c){
    FillOneQuadrantLeftHalf(n);
    FlipMatrixVerticalAxis(n);
  }
}

void FillMatrix(int n, vector<int>& cornerPoints){
  M[1][1] = cornerPoints[0];
  M[1][n] = cornerPoints[1];
  M[n][1] = cornerPoints[2];
  M[n][n] = cornerPoints[3];

  for(int c = 0; c < 4; ++c){
    FillOneQuadrant(n);
    RotateMatrixBy90CW(n);
  }
}

bool Check(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      vector<int> v;
      for(int di = -1; di < 2; ++di){
        for(int dj = -1; dj < 2; ++dj){
          int ni = i + di, nj = j + dj;
          if(ni <= 0 || ni > n || nj <= 0 || nj > n || (di == 0 && dj == 0)){
            continue;
          }
          v.PB(M[ni][nj]);
        }
      }
      sort(v.begin(), v.end());
      if(v != adj[M[i][j]]){
        return 0;
      }
    }
  }
  return 1;
}

bool FillMatrixAndCheck(int n, vector<int>& cornerPoints){
  FillMatrix(n, cornerPoints);
  return Check(n);
}

bool Solve(int n, vector<int> cornerPoints){
  for(auto i : cornerPoints){
    if(!BFS(n * n, i, d[i])){
      return 0;
    }
  }

  int c = 0;
  for(sort(cornerPoints.begin(), cornerPoints.end()); c < 4; next_permutation(cornerPoints.begin(), cornerPoints.end()), ++c){
    if(FillMatrixAndCheck(n, cornerPoints)){
      return 1;
    }
  }

  return 0;
}

void StressTest(){
  srand(0);
  while(true){
    int n = 50 + 50 * (rand() % 4), m = 0;

    vector<int> v;
    for(int i = 1; i <= n * n; ++i){
      v.PB(i);
    }

    random_shuffle(v.begin(), v.end());

    for(int i = 1, k = 0; i <= n; ++i){
      for(int j = 1; j <= n; ++j, ++k){
        M[i][j] = v[k];
      }
    }

    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        for(int di = -1; di < 2; ++di){
          for(int dj = -1; dj < 2; ++dj){
            int ni = i + di, nj = j + dj;
            if(ni <= 0 || ni > n || nj <= 0 || nj > n || (di == 0 && dj == 0)){
              continue;
            }
            m += (M[i][j] < M[ni][nj]);
            adj[M[i][j]].PB(M[ni][nj]);
          }
        }
      }
    }

    vector<int> cornerPoints;
    for(int i = 1; i <= n * n; ++i){
      sort(adj[i].begin(), adj[i].end());
      if(adj[i].size() == 3){
        cornerPoints.PB(i);
      }
    }

    printf("%d %d\n", n, m);
    if(!Solve(n, cornerPoints)){
      for(int i = 1, k = 0; i <= n; ++i){
        for(int j = 1; j <= n; ++j, ++k){
          M[i][j] = v[k];
        }
      }
      for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
          for(int di = -1; di < 2; ++di){
            for(int dj = -1; dj < 2; ++dj){
              int ni = i + di, nj = j + dj;
              if(ni <= 0 || ni > n || nj <= 0 || nj > n || (di == 0 && dj == 0)){
                continue;
              }
              if(M[i][j] < M[ni][nj]){
                printf("%d %d\n", M[i][j], M[ni][nj]);
              }
            }
          }
        }
      }
      for(int i = 1, k = 0; i <= n; ++i){
        for(int j = 1; j <= n; ++j, ++k){
          printf("%d ", v[k]);
        }
        printf("\n");
      }
      break;
    }

    for(int i = 1; i <= n * n; ++i){
      adj[i].clear();
    }
  }
}

int main(){
  StressTest();
  return 0;
}
