#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1004

int d[N][N];
queue<pii> Q;

void CheckAndPush(int x, int y, int dxy){
  if(x <= 0 || x >= N || y <= 0 || y >= N || d[x][y] != INT_MAX){
    return;
  }
  d[x][y] = dxy;
  Q.push({x, y});
}

void Initialize(){
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      d[x][y] = INT_MAX;
    }
  }

  CheckAndPush(1, 1, 0);

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    int nd = 1 + d[x][y];

    CheckAndPush(x - 2, y - 1, nd);
    CheckAndPush(x - 2, y + 1, nd);
    CheckAndPush(x - 1, y - 2, nd);
    CheckAndPush(x - 1, y + 2, nd);
    CheckAndPush(x + 1, y - 2, nd);
    CheckAndPush(x + 1, y + 2, nd);
    CheckAndPush(x + 2, y - 1, nd);
    CheckAndPush(x + 2, y + 1, nd);
  }
}

int Solve(){
  int x, y;
  scanf("%d%d", &x, &y);
  return d[x][y];
}

int main(){
  Initialize();
  
  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}