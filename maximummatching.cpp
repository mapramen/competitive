#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 4
#define B (1 << M)

vector< vector<int> > v(B);
int s[B], adj[M][M], degree[M], visited[M];

void DFS(int i){
  visited[i] = 1;
  for(int j = 0; j < M; ++j){
    if(adj[i][j] == 1 && visited[j] == 0){
      DFS(j);
    }
  }
}

bool CheckEuler(){
  int oddDegreeCount = 0, root = 0;
  for(int i = 0; i < M; ++i){
    oddDegreeCount += (degree[i] % 2);
    if(degree[i]){
      root = i;
    }
  }

  if(oddDegreeCount % 2 == 1 || oddDegreeCount > 2){
    return 0;
  }

  DFS(root);

  for(int i = 0; i < M; ++i){
    if(degree[i] == 0){
      continue;
    }
    if(visited[i] == 0){
      return 0;
    }
  }

  return 1;
}

int main(){
  int n;

  cin >> n;

  while(n--){
    int i, val, j;
    cin >> i >> val >> j;
    if(i > j){
      swap(i, j);
    }
    --i, --j;
    int x = i * M + j;
    v[x].PB(val);
  }

  for(int i = 0; i < B; ++i){
    for(auto x : v[i]){
      s[i] += x;
    }
    sort(v[i].begin(), v[i].end());
  }

  int ans = 0;
  for(int i = 0; i < M; ++i){
    int x = i * M + i;
    ans = max(ans, s[x]);
  }

  for(int mask = 1; mask < (1 << B); ++mask){
    bool valid = 1;
    for(int i = 0; i < M; ++i){
      int x = i * M + i;
      if((mask & (1 << x)) > 0){
        valid = 0;
        break;
      }
    }

    if(!valid){
      continue;
    }

    for(int i = 0; i < M; ++i){
      for(int j = 0; j < M; ++j){
        adj[i][j] = 0;
      }
      degree[i] = 0;
      visited[i] = 0;
    }

    for(int x = 0; x < B; ++x){
      if((mask & (1 << x)) == 0){
        continue;
      }
      int i = x / M, j = x % M;
      adj[i][j] = 1;
      ++degree[i];
      ++degree[j];
    }

    int ansx = 0;
    for(int i = 0; i < M && valid == 1; ++i){
      for(int j = i + 1; j < M && valid == 1; ++j){
        int x = i * M + j, k = adj[i][j] + adj[j][i];

        if(k == 0){
          continue;
        }

        if(v[x].size() < k){
          valid = 0;
          break;
        }

        if((v[x].size() - k) % 2 == 1){
          ansx += (s[x] - v[x].front());
        }
        else{
          ansx += s[x];
        }

        adj[i][j] = adj[j][i] = 1;
      }
    }

    if(!valid || !CheckEuler()){
      continue;
    }

    for(int i = 0; i < M; ++i){
      if(visited[i]){
        int x = i * M + i;
        ansx += s[x];
      }
    }

    ans = max(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}
