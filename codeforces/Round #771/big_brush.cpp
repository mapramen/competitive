#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 1000

int n, m, A[N][N], B[N][N], C[N][N];
queue<pii> Q;
vector<tiii> ans;
set<int> S;

void Stamp(int A[N][N], int x, int y, int c){
  for(int nx = x, dx = 0; dx < 2; ++dx, ++nx){
    for(int ny = y, dy = 0; dy < 2; ++dy, ++ny){
      A[nx][ny] = c;
    }
  }
}

void CheckAndPush(int x, int y){
  if(x < 0 || x + 1 >= n || y < 0 || y + 1 >= m){
    return;
  }

  S.clear();
  for(int nx = x, dx = 0; dx < 2; ++dx, ++nx){
    for(int ny = y, dy = 0; dy < 2; ++dy, ++ny){
      if(A[nx][ny] == 0){
        continue;
      }
      S.insert(A[nx][ny]);
    }
  }

  if(S.size() != 1){
    return;
  }

  Stamp(A, x, y, 0);  

  ans.push_back({x, y, *S.begin()});
  Q.push({x, y});
}

int main(){
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      int c;
      scanf("%d", &c);

      A[x][y] = c, B[x][y] = c;
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      CheckAndPush(x, y);
    }
  }

  while(!Q.empty()){
    auto [x, y] = Q.front();
    Q.pop();

    for(int dx = -1; dx < 2; ++dx){
      for(int dy = -1; dy < 2; ++dy){
        CheckAndPush(x + dx, y + dy);
      }
    }
  }
  
  reverse(ans.begin(), ans.end());

  for(auto [x, y, c]: ans){
    Stamp(C, x, y, c);
  }

  bool valid = true;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      valid = valid && (B[x][y] == C[x][y]);
    }
  }

  if(!valid){
    printf("-1\n");
    return 0;
  }

  printf("%lu\n", ans.size());
  for(auto [x, y, c]: ans){
    printf("%d %d %d\n", x + 1, y + 1, c);
  }
  
  return 0;
}