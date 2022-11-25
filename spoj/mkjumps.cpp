#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10

vector<pii> moves {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
bool visited[N][N];

void Reset(){
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      visited[x][y] = true;
    }
  }
}

int DFS(int x, int y){
  if(x < 0 || y < 0 || x >= N || y >= N || visited[x][y]){
    return 0;
  }

  visited[x][y] = true;
  
  int ans = 0;
  for(pii& move: moves){
    ans = max(ans, DFS(x + move.first, y + move.second));
  }

  visited[x][y] = false;
  return 1 + ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  Reset();

  int total = 0;
  for(int x = 0; x < n; ++x){
    int l, r;
    scanf("%d%d", &l, &r);
    r += l;

    for(int y = l; y < r; ++y){
      visited[x][y] = false;
    }

    total += (r - l);
  }

  return total - DFS(0, 0);
}

int main(){
  for(int k = 1; ; ++k){
    int cnt = Solve();
    printf("Case %d, %d %s can not be reached.\n", k, cnt, cnt == 1 ? "square" : "squares");
  }
  return 0;
}