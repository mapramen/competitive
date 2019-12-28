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

const int inf = 1000000000;

int main(){
  int n, sx, sy, px = 0, py = 0, nx = 0, ny = 0;

  scanf("%d%d%d", &n, &sx, &sy);
  while(n--){
    int x, y;
    scanf("%d%d", &x, &y);
    x -= sx, y -= sy;

    if(x != 0){
      if(x < 0){
        ++nx;
      }
      else{
        ++px;
      }
    }

    if(y != 0){
      if(y < 0){
        ++ny;
      }
      else{
        ++py;
      }
    }
  }

  int ans = max(max(px, nx), max(py, ny));

  if(ans == px && sx < inf){
    ++sx;
  }
  else if(ans == nx && sx > 0){
    --sx;
  }
  else if(ans == py && sy < inf){
    ++sy;
  }
  else{
    --sy;
  }

  printf("%d\n%d %d\n", ans, sx, sy);

  return 0;
}