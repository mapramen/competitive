#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

int A[N][N];
vector<int> adj[N * N], d[N * N];

bool BFS(int n, int s, vector<int>& d){
  d.clear();
  d.resize(n + 1);

  for(int i = 1; i <= n; ++i){
    d[i] = n;
  }

  queue<int> Q;
  Q.push(s);
  d[s] = 0;

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
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

  return 1;
}

bool Solve(int n, vector<int> cornerPoints){
  for(auto i : cornerPoints){
    if(!BFS(n * n, i, d[i])){
      return 0;
    }
  }

  for(int i = 1; i < cornerPoints.size(); ++i){
    if(d[cornerPoints[0]][cornerPoints[i]] > d[cornerPoints[0]][cornerPoints[3]]){
      swap(cornerPoints[i], cornerPoints[3]);
    }
  }

  vector< pii > corners{{1, 1}, {1, n}, {n, 1}, {n, n}};
  map< vector<int>, int > M;

  for(int x = 1; x <= n * n; ++x){
    vector<int> v;
    for(int k = 0; k < 4; ++k){
      v.PB(d[cornerPoints[k]][x]);
    }
    if(M.count(v)){
      return 0;
    }
    M[v] = x;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      vector<int> v;
      for(int k = 0; k < 4; ++k){
        v.PB((abs(i - corners[k].first) + abs(j - corners[k].second) + 1) / 2);
      }
      if(M.count(v) == 0){
        return 0;
      }
      A[i][j] = M[v];
    }
  }

  return 1;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, m;

    scanf("%d%d", &n, &m);

    while(m--){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
      adj[j].PB(i);
    }

    m = INT_MAX;
    for(int i = 1; i <= n * n; ++i){
      m = min(m, (int)adj[i].size());
    }

    vector<int> cornerPoints;
    for(int i = 1; i <= n * n; ++i){
      if(adj[i].size() == m){
        cornerPoints.PB(i);
      }
    }

    if(n == 1){
      for( ; cornerPoints.size() < 4; cornerPoints.PB(1));
    }

    if(cornerPoints.size() != 4 || !Solve(n, cornerPoints)){
      printf("-1\n");
    }
    else{
      for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
          printf("%d ", A[i][j]);
        }
        printf("\n");
      }
    }

    for(int i = 1; i <= n * n; ++i){
      adj[i].clear();
    }
  }

  return 0;
}
