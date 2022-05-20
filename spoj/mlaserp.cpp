#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 101
#define B 4

char s[N][N];
int n, m, d[B][N][N];
deque<tiii> Q;

void CheckAndPush(int k, int x, int y, int val, bool front){
  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '*' || val >= d[k][x][y]){
    return;
  }
  
  d[k][x][y] = val;
  if(front){
    Q.push_front({k, x, y});
  }
  else{
    Q.push_back({k, x, y});
  }
}

int main(){
  scanf("%d%d", &m, &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  vector<pii> cows;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'C'){
        cows.push_back({x, y});
      }

      for(int k = 0; k < B; ++k){
        d[k][x][y] = INT_MAX;
      }
    }
  }

  int sx = cows[0].first, sy = cows[0].second;
  int tx = cows[1].first, ty = cows[1].second;

  for(int k = 0; k < B; ++k){
    CheckAndPush(k, sx, sy, 0, false);
  }

  while(!Q.empty()){
    int x, y, k;
    tie(k, x, y) = Q.front();
    Q.pop_front();

    int val = d[k][x][y];
    if(x == tx && y == ty){
      printf("%d\n", val);
      return 0;
    }

    if(k == 0){
      CheckAndPush(0, x - 1, y, val, true);
      CheckAndPush(1, x, y, val + 1, false);
      CheckAndPush(3, x, y, val + 1, false);
    }
    else if(k == 1){
      CheckAndPush(1, x, y + 1, val, true);
      CheckAndPush(0, x, y, val + 1, false);
      CheckAndPush(2, x, y, val + 1, false);
    }
    else if(k == 2){
      CheckAndPush(2, x + 1, y, val, true);
      CheckAndPush(1, x, y, val + 1, false);
      CheckAndPush(3, x, y, val + 1, false);
    }
    else{
      CheckAndPush(3, x, y - 1, val, true);
      CheckAndPush(0, x, y, val + 1, false);
      CheckAndPush(2, x, y, val + 1, false);
    }
  }

  return 0;
}