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
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 8

vector<pii> adj[N][N];
int a[N][N];

void Initialise(){
  vector<pii> moves;

  for(int dx = -2; dx < 3; ++dx){
    for(int dy = -2; dy < 3; ++dy){
      if(abs(dx) + abs(dy) != 3){
        continue;
      }
      moves.push_back({dx, dy});
    }
  }

  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      for(pii p: moves){
        auto [dx, dy] = p;
        int nx = x + dx, ny = y + dy;
        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
          continue;
        }
        adj[x][y].push_back({nx, ny});
      }
    }
  }
}

int Degree(int x, int y){
  int ans = 0;
  
  for(pii p: adj[x][y]){
    auto [nx, ny] = p;
    if(a[nx][ny] == 0){
      ++ans;
    }
  }

  return ans;
}

vector<pii> NextMoves(int x, int y){
  vector<tiii> v;
  for(pii p: adj[x][y]){
    auto [nx, ny] = p;
    if(a[nx][ny]){
      continue;
    }
    v.push_back({Degree(nx, ny), nx, ny});
  }
  sort(v.begin(), v.end());

  vector<pii> ans;
  for(auto t: v){
    auto [d, nx, ny] = t;
    ans.push_back({nx, ny});
  }
  return ans;
}

void Print(){
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      printf("%d ", a[x][y]);
    }
    printf("\n");
  }
}

bool DFS(int k, int x, int y){
  a[x][y] = k;
  
  if(k == N * N){
    Print();
    return true;
  }

  for(auto p: NextMoves(x, y)){
    if(DFS(k + 1, p.first, p.second)){
      return true;
    }
  }

  a[x][y] = 0;
  return false;
}

int main(){
  int x, y;

  cin >> y >> x;
  --x, --y;

  Initialise();

  DFS(1, x, y);

  return 0;
}