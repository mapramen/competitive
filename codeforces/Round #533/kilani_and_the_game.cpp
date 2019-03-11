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
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define N 1001
#define B 10

char s[N][N];
queue< tiii > Q[B];
int n, m, r[B], ans[B];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(int k, int D, queue< tiii > &Q){
  while(!Q.empty()){
    int d, x, y;
    tie(d, x, y) = Q.front();
    
    if(d == D){
      break;
    }

    Q.pop();

    for(int kx = 0; kx < 4; ++kx){
      int nx = x + dx[kx], ny = y + dy[kx];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.'){
        continue;
      }
      s[nx][ny] = '0' + k;
      Q.push(make_tuple(d + 1, nx, ny));
    }
  }
}

int main(){
  int k;

  scanf("%d%d%d", &n, &m, &k);
  
  for(int i = 1; i <= k; ++i){
    scanf("%d", &r[i]);
  }

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      char c = s[i][j];
      if(c < '1' || c > '9'){
        continue;
      }
      Q[c - '0'].push(make_tuple(0, i, j));
    }
  }

  for(int d = 1; ; ++d){
    bool allCastlesVisited = true;

    for(int i = 1; i <= k; ++i){
      if(Q[i].empty()){
        continue;
      }
      BFS(i, d * r[i], Q[i]);
      allCastlesVisited &= Q[i].empty();
    }

    if(allCastlesVisited){
      break;
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      char c = s[i][j];
      if(c < '0' || c > '9'){
        continue;
      }
      ++ans[c - '0'];
    }
  }

  for(int i = 1; i <= k; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}