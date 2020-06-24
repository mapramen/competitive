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
#define N 1001

int n, m;
char s[N][N];

void DFS(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '#'){
    return;
  }

  s[x][y] = '#';
  DFS(x - 1, y);
  DFS(x, y - 1);
  DFS(x, y + 1);
  DFS(x + 1, y);
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  int ans = 0;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '#'){
        continue;
      }
      ++ans;
      DFS(x, y);
    }
  }

  printf("%d\n", ans);
  
  return 0;
}