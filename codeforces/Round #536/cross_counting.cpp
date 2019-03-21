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

#define pii pair< int, int>
#define pll pair< ll, ll>
#define N 501

char s[N][N];
int dx[] = {0, -1, -1, 1, 1};
int dy[] = {0, -1, 1, -1, 1};

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  int ans = 0;
  for(int x = 2; x < n; ++x){
    for(int y = 2; y < n; ++y){
      bool valid = true;
      for(int k = 0; k < 5 && valid; ++k){
        int nx = x + dx[k], ny = y + dy[k];
        valid = s[nx - 1][ny - 1] == 'X';
      }
      ans += valid;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}