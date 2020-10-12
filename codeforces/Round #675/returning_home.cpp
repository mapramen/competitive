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
#define tiii tuple<int,int,int>
#define N 100001

vector<vector<pii>> adj(N);
priority_queue<pii,vector<pii>,greater<pii>> Q;
vector<tiii> X, Y;
pii a[N];
int dis[N];
bool visited[N];

void AddPoint(int i, int x, int y){
  a[i] = {x, y};
  X.push_back({x, y, i});
  Y.push_back({y, x, i});
}

void Relax(int i, int d){
  if(d < dis[i]){
    dis[i] = d;
    Q.push({d, i});
  }
}

int main(){
  int n, m, sx, sy, tx, ty;

  scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &tx, &ty);

  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    AddPoint(i, x, y);
  }
  AddPoint(0, sx, sy);

  for(auto &s: vector{X, Y}){
    sort(s.begin(), s.end());
    for(int i = 1; i <= m; ++i){
      auto [x1, y1, u] = s[i - 1];
      auto [x2, y2, v] = s[i];
      int d = min(abs(x2 - x1), abs(y2 - y1));
      adj[u].push_back({v, d});
      adj[v].push_back({u, d});
    }
  }

  for(int i = 0; i <= m; ++i){
    dis[i] = n;
  }

  Relax(0, 0);

  while(!Q.empty()){
    auto [d, i] = Q.top();
    Q.pop();

    if(visited[i]){
      continue;
    }

    for(auto p: adj[i]){
      Relax(p.first, d + p.second);
    }

    visited[i] = true;
  }

  int ans = 2 * n;
  for(int i = 0; i <= m; ++i){
    int ansx = dis[i] + abs(a[i].first - tx) + abs(a[i].second - ty);
    ans = min(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}