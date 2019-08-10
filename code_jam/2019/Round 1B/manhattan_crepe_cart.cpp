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
#define N 3010

int Q, c[N][N], X[N], Y[N];
char dir[N];
vector<int> v;

void Add(int x){
  v.push_back(min(Q, max(0, x)));
}

int GetCompressedValue(int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void Update(int x1, int y1, int x2, int y2){
  ++c[x1][y1];
  --c[x1][y2 + 1];
  --c[x2 + 1][y1];
  ++c[x2 + 1][y2 + 1];
}

void Solve(){
  int n, m;
  string s;

  scanf("%d%d", &n, &Q);

  for(int i = 1; i <= n; ++i){
    cin >> X[i] >> Y[i] >> s;
    dir[i] = s[0];
  }

  v.clear();
  v.push_back(0);
  v.push_back(Q);

  for(int i = 1; i <= n; ++i){
    Add(X[i] - 1);
    Add(X[i]);
    Add(X[i] + 1);
    Add(Y[i] - 1);
    Add(Y[i]);
    Add(Y[i] + 1);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  m = v.size();
  for(int i = 0; i <= m; ++i){
    for(int j = 0; j <= m; ++j){
      c[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    X[i] = GetCompressedValue(X[i]);
    Y[i] = GetCompressedValue(Y[i]);

    int x1 = 1, y1 = 1, x2 = m, y2 = m;
    char d = dir[i];

    if(d == 'N'){
      y1 = Y[i] + 1;
    }
    else if(d == 'S'){
      y2 = Y[i] - 1;
    }
    else if(d == 'E'){
      x1 = X[i] + 1;
    }
    else{
      x2 = X[i] - 1;
    }

    Update(x1, y1, x2, y2);
  }

  int x = 1, y = 1;
  for(int i = 1; i <= m; ++i){
    for(int j = 1; j <= m; ++j){
      c[i][j] += (c[i][j - 1] + c[i - 1][j] - c[i - 1][j - 1]);
      if(c[x][y] < c[i][j]){
        x = i, y = j;
      }
    }
  }

  x = v[x - 1], y = v[y - 1];
  printf("%d %d\n", x, y);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; ++i){
    printf("Case #%d: ", i);
    Solve();
  }
  return 0;
}