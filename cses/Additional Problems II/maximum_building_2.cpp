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
#define N 1002

char s[N];
int a[N];
ll B[N][N], C[N][N];
stack<int> S, P;

void UpdateCount(int x, int y, int k){
  if(x == 0 || y == 0){
    return;
  }

  B[x][y] += k * (y + 1);
  C[x][y] += k;
}

void Update(int i, int x){
  int j = i;

  while(S.top() > x){
    int a = S.top();
    j = P.top();
    S.pop(), P.pop();

    UpdateCount(a, i - j, 1);
    UpdateCount(max(S.top(), x), i - j, -1);
  }

  if(S.top() != x){
    S.push(x), P.push(j);
  }
}

void RectangleCount(int n){
  for(int i = 1; i <= n; ++i){
    Update(i, a[i]);
  }
  Update(n + 1, 0);
}

void CumulativeSum(int n, int m, ll C[N][N]){
  for(int y = 1; y <= m; ++y){
    for(int x = n - 1; x > 0; --x){
      C[x][y] += C[x + 1][y];
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = m - 1; y > 0; --y){
      C[x][y] += C[x][y + 1];
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  S.push(0), P.push(0);
  for(int i = 0; i < n; ++i){
    scanf("%s", s);
    for(int j = 1; j <= m; ++j){
      if(s[j - 1] == '*'){
        a[j] = 0;
      }
      else{
        ++a[j];
      }
    }
    RectangleCount(m);
  }

  CumulativeSum(n, m, B);
  CumulativeSum(n, m, C);

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      int ans = B[x][y] - C[x][y] * y;
      printf("%d ", ans);
    }
    printf("\n");
  }

  return 0;
}