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

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 51

int n, m;
char s[N][N];

bool CheckAndBlock(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= m){
    return true;
  }

  if(s[x][y] == 'G'){
    return false;
  }

  if(s[x][y] == '.'){
    s[x][y] = '#';
  }

  return true;
}

void dfs(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '#' || s[x][y] == 'B'){
    return;
  }

  s[x][y] = '#';
  dfs(x - 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
  dfs(x + 1, y);
}

bool Solve(){
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(s[i][j] != 'B'){
        continue;
      }
      if(!(CheckAndBlock(i - 1, j) && CheckAndBlock(i, j - 1) && CheckAndBlock(i, j + 1) && CheckAndBlock(i + 1, j))){
        return false;
      }
    }
  }

  dfs(n - 1, m - 1);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(s[i][j] == 'G'){
        return false;
      }
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}