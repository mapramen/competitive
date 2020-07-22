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
#define tcii tuple<char,int,int>
#define N 1001

char s[N][N], parentMove[N][N];
int n, m;
queue<tcii> Q;

void CheckAndPush(char move, int x, int y, char c){
  if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '#'){
    return;
  }
  s[x][y] = '#';
  parentMove[x][y] = move;
  Q.push({c, x, y});
}

void GetParent(int &x, int &y, char move){
  if(move == 'U'){
    ++x;
  }
  else if(move == 'D'){
    --x;
  }
  else if(move == 'L'){
    ++y;
  }
  else if(move == 'R'){
    --y;
  }
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'M'){
        CheckAndPush('-', x, y, s[x][y]);
      }
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'A'){
        CheckAndPush('-', x, y, s[x][y]);
      }
    }
  }

  int sx = -1, sy = -1;
  while(!Q.empty()){
    auto [c, x, y] = Q.front();
    Q.pop();

    if(c == 'A' && (x == 0 || x == n - 1 || y == 0 || y == m - 1)){
      sx = x, sy = y;
      break;
    }

    CheckAndPush('U', x - 1, y, c);
    CheckAndPush('D', x + 1, y, c);
    CheckAndPush('L', x, y - 1, c);
    CheckAndPush('R', x, y + 1, c);
  }

  if(sx == -1){
    printf("NO\n");
    return 0;
  }

  string ans;
  for( ; parentMove[sx][sy] != '-'; GetParent(sx, sy, parentMove[sx][sy])){
    ans.push_back(parentMove[sx][sy]);
  }
  reverse(ans.begin(), ans.end());

  printf("YES\n%lu\n%s\n", ans.size(), ans.c_str());

  return 0;
}