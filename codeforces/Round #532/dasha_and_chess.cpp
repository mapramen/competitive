#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 667
#define M 1000

int X[N], Y[N];
set<int> rows[M], columns[M];

void Add(int x, int y){
  rows[x].insert(y);
  columns[y].insert(x);
}

void Remove(int x, int y){
  rows[x].erase(y);
  columns[y].erase(x);
}

void Update(int k, int x, int y){
  Remove(X[k], Y[k]);
  Add(x, y);
  X[k] = x, Y[k] = y;
}

bool IsPositionAvailableOnBoard(int x, int y){
  return x > 0 && x < M && y > 0 && y < M && rows[x].count(y) == 0;
}

bool IsPositionInCheck(int x, int y){
  return IsPositionAvailableOnBoard(x, y) && (!rows[x].empty() || !columns[y].empty());
}

int GetCornerDirectionRookCount(int dx, int dy){
  int ans = 0;
  for(int x = M / 2; x > 0 && x < M; x += dx){
    for(int y = M / 2; y > 0 && y < M; y += dy){
      ans += rows[x].count(y);
    }
  }
  return ans;
}

pii GetCornerDirection(){
  int c = INT_MAX;
  pii ans;
  for(int dx = -1; dx < 2; dx += 2){
    for(int dy = -1; dy < 2; dy += 2){
      int cx = GetCornerDirectionRookCount(dx, dy);
      if(cx < c){
        c = cx;
        ans = make_pair(-dx, -dy);
      }
    }
  }
  return ans;
}

pii GetInCheckMove(int x, int y){
  for(int dx = -1; dx < 2; ++dx){
    for(int dy = -1; dy < 2; ++dy){
      if(dx == 0 && dy == 0){
        continue;
      }
      int nx = x + dx, ny = y + dy;
      if(IsPositionInCheck(nx, ny)){
        return make_pair(nx, ny);
      }
    }
  }
  return make_pair(INT_MIN, INT_MIN);
}

pii GetCenterMove(int x, int y){
  pii ans = GetInCheckMove(x, y);

  if(ans.first > 0){
    return ans;
  }

  int dx = M / 2 - x, dy = M / 2 - y;
  dx /= max(1, abs(dx));
  dy /= max(1, abs(dy));

  return make_pair(x + dx, y + dy);
}

pii GetCornerMove(int x, int y, int dx, int dy){
  pii ans = GetInCheckMove(x, y);

  if(ans.first > 0){
    return ans;
  }

  if(IsPositionAvailableOnBoard(x + dx, y + dy)){
    return make_pair(x + dx, y + dy);
  }
  else{
    return make_pair(x, y);
  }
}

bool MakeMoveAndCheckGameOver(int x, int y){
  cout << x << ' ' << y << '\n';
  fflush(stdout);

  int k;
  cin >> k >> x >> y;

  if(k <= 0 || k >= N){
    return true;
  }

  Update(k, x, y);
  return false;
}

int main(){
  int kx, ky;

  cin >> kx >> ky;

  for(int k = 1; k < N; ++k){
    cin >> X[k] >> Y[k];
    Add(X[k], Y[k]);
  }

  while(kx != M / 2 || ky != M / 2){
    tie(kx, ky) = GetCenterMove(kx, ky);
    if(MakeMoveAndCheckGameOver(kx, ky)){
      return 0;
    }
  }

  int dx, dy;
  tie(dx, dy) = GetCornerDirection();

  while(true){
    tie(kx, ky) = GetCornerMove(kx, ky, dx, dy);
    if(MakeMoveAndCheckGameOver(kx, ky)){
      return 0;
    }
  }

  return 0;
}