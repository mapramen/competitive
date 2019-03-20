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
#define N 5201

int A[N][N];
char s[N];

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      A[i][j] += (A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1]);
    }
  }
}

int Query(int x1, int y1, int x2, int y2){
  return A[x2][y2] + A[x1 - 1][y1 - 1] - A[x2][y1 - 1] - A[x1 - 1][y2];
}

bool Check(int i, int j, int x){
  int x1 = (i - 1) * x + 1, y1 = (j - 1) * x + 1;
  int x2 = x1 + x - 1, y2 = y1 + x - 1;
  int cnt = Query(x1, y1, x2, y2);
  return (cnt == 0 || cnt == x * x);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%s", s);
    for(int j = 1, k = 0; j <= n; j += 4, ++k){
      char c = s[k];
      int x = ('0' <= c && c <= '9') ? c - '0' : 10 + c - 'A';
      for(int y = 3; y > -1; --y, x /= 2){
        A[i][j + y] = x % 2;
      }
    }
  }

  PreProcess(n);

  int ans = 1;
  for(int x = 2; x <= n; ++x){
    if(n % x != 0){
      continue;
    }
    bool valid = true;
    int m = n / x;
    for(int i = 1; i <= m && valid; ++i){
      for(int j = 1; j <= m && valid; ++j){
        valid = Check(i, j, x);
      }
    }
    if(valid){
      ans = x;
    }
  }

  printf("%d\n", ans);

  return 0;
}