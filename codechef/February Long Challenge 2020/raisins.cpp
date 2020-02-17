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
#include <time.h>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define pci pair<char,int>
#define N 720720
#define M 1024

ll minArea;
int ansN = 1, ansM = 1;
vector< vector< vector< pii > > > grid;
vector< pii > pts, nms, ans, cur;

ll cross(pii p, pii q){
  return 1ll * p.first * q.second - 1ll * p.second * q.first;
}

ll area2(pii a, pii b, pii c){
  return cross(a, b) + cross(b, c) + cross(c, a);
}

vector<pii> convexHull(vector<pii> pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  
  vector<pii> up, dn;
  
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }

  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

  return pts;
}

ll area(vector<pii> &pts){
  auto hull = convexHull(pts);

  const int n = hull.size();
  ll ans = 0;
  
  for(int i = 0; i < n; i++) {
    ans += cross(hull[i], hull[(i + 1) % n]);
  }
  
  return abs(ans);
}

void InitializeGrid(int n, int m){
  for(int i = 0; i < grid.size(); ++i){
    for(int j = 0; j < grid[i].size(); ++j){
      grid[i][j].clear();
    }
    grid[i].clear();
  }
  grid.clear();

  grid.resize(n);
  for(int i = 0; i < n; ++i){
    grid[i].resize(m);
  }

  const int w = N / n, h = N / m;

  for(auto p : pts){
    int x, y;
    tie(x, y) = p;
    grid[(x / w)][(y / h)].push_back(make_pair(x % w, y % h));
  }
}

void ShiftRow(int n, int m, int r){
  cur.push_back(make_pair(1, r + 1));

  for(int c = 1; c < n; ++c){
    swap(grid[0][r], grid[c][r]);
  }
}

void ShiftColumn(int n, int m, int c){
  cur.push_back(make_pair(2, c + 1));

  for(int r = 1; r < m; ++r){
    swap(grid[c][0], grid[c][r]);
  }
}

void TakeInput(){
  int w, h, n;

  scanf("%d%d%d", &w, &h, &n);
  while(n--){
    int x, y;
    scanf("%d%d", &x, &y);
    pts.push_back(make_pair(x, y));
  }
}

void Initialize(){
  vector<int> v;

  for(int d = 2; d <= M; ++d){
    if(N % d == 0){
      v.push_back(d);
    }
  }

  for(int n : v){
    for(int m : v){
      if(n == m && n * m <= M){
        nms.push_back(make_pair(n, m));
      }
    }
  }

  minArea = area(pts);

  v.clear();

  srand(time(NULL));
}

void RandomWalk(){
  int n, m;
  tie(n, m) = nms[rand() % nms.size()];

  InitializeGrid(n, m);

  for(int i = 0; i < M; ++i){
    if(rand() % 2 == 0){
      ShiftRow(n, m, rand() % m);
    }
    else{
      ShiftColumn(n, m, rand() % n);
    }
  }

  const int w = N / n, h = N / m;
  vector< pii > v;
  
  for(int r = 0; r < n; ++r){
    for(int c = 0; c < m; ++c){
      for(auto p : grid[r][c]){
        v.push_back(make_pair(r * w + p.first, c * h + p.second));
      }
    }
  }

  int curArea = area(v);
  if(curArea < minArea){
    minArea = curArea, ansN = n, ansM = m, swap(ans, cur);
  }

  v.clear(), cur.clear();
}

int main(){
  TakeInput();
  
  Initialize();
  
  for(clock_t startClock = clock(); (clock() - startClock) <= 4.94 * CLOCKS_PER_SEC; ){
    RandomWalk();
  }

  printf("%d %d %lu\n", ansN, ansM, ans.size());
  for(auto p : ans){
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}