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
#define N 7
#define M (N * N)
 
bool visited[N][N];
char s[M], lastMove = 'X';
int steps = 0, ans = 0;
 
void DFS(int x, int y){
  if((steps == M - 1) != (x == N - 1 && y == 0)){
    return;
  }

  if(steps == M - 1){
    if(x == N - 1 && y == 0){
      ++ans;
    }
    return;
  }

  if(lastMove == 'D' && (x == N - 1 || visited[x + 1][y]) && y != 0 && y != N - 1 && !visited[x][y - 1] && !visited[x][y + 1]){
    return;
  }
 
  if(lastMove == 'U' && (x == 0 || visited[x - 1][y]) && y != 0 && y != N - 1 && !visited[x][y - 1] && !visited[x][y + 1]){
    return;
  }
 
  if(lastMove == 'R' && (y == N - 1 || visited[x][y + 1]) && x != 0 && x != N - 1 && !visited[x - 1][y] && !visited[x + 1][y]){
    return;
  }
 
  if(lastMove == 'L' && (y == 0 || visited[x][y - 1]) && x != 0 && x != N - 1 && !visited[x - 1][y] && !visited[x + 1][y]){
    return;
  }
 
  visited[x][y] = true;
  
  char c = s[steps++];
 
  if((c == 'D' || c == '?') && (x != N - 1 && !visited[x + 1][y])){
    lastMove = 'D';
    DFS(x + 1, y);
  }
 
  if((c == 'U' || c == '?') && (x != 0 && !visited[x - 1][y])){
    lastMove = 'U';
    DFS(x - 1, y);
  }
 
  if((c == 'R' || c == '?') && (y != N - 1 && !visited[x][y + 1])){
    lastMove = 'R';
    DFS(x, y + 1);
  }
 
  if((c == 'L' || c == '?') && (y != 0 && !visited[x][y - 1])){
    lastMove = 'L';
    DFS(x, y - 1);
  }
 
  visited[x][y] = false;
  --steps;
}
 
int main(){
  scanf("%s", s);
 
  DFS(0, 0);
 
  printf("%d\n", ans);
  
  return 0;
}