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
#define N 100002

vector<vector<int>> V(N), U(N);
int a[N], b[N];
bool marked[N];
priority_queue<pii> Q;

void CheckAndPush(int i){
  if(V[i].empty()){
    return;
  }
  Q.push({V[i].size(), i});
}

int ExtractIndex(int i){
  int ans = V[i].back();
  V[i].pop_back();
  return ans;
}

vector<int> GetRemaining(int n){
  int s = 0;
  for(int i = 1; i <= n + 1; ++i){
    s += V[i].size();
  }

  while(!Q.empty() && 2 * Q.top().first > s){
    int i = Q.top().second;
    Q.pop();
    ExtractIndex(i);
    CheckAndPush(i);
    --s;
  }

  int m = Q.empty() ? 1 : Q.top().first;

  for(int x = 0; !Q.empty(); ){
    int i = Q.top().second;
    Q.pop();
    while(!V[i].empty()){
      U[x].push_back(ExtractIndex(i));
      x = (x + 1) % m;
    }
  }

  vector<int> v;
  for(int x = 0; !U[x].empty(); ++x){
    v.insert(v.end(), U[x].begin(), U[x].end());
    U[x].clear();
  }

  return v;
}

bool Solve(int n, int x, int y){
  for(int i = 1; i <= n + 1; ++i){
    V[i].clear();
    marked[i] = false;
  }

  for( ; !Q.empty(); Q.pop());

  for(int j = 1; j <= n; ++j){
    int i;
    scanf("%d", &i);
    b[j] = i;
    V[i].push_back(j);
    marked[i] = true;
  }

  int nullNumber = 1;
  for( ; marked[nullNumber]; ++nullNumber);

  for(int j = 1; j <= n; ++j){
    a[j] = nullNumber;
  }

  for(int i = 1; i <= n + 1; ++i){
    CheckAndPush(i);
  }

  y -= x;

  while(!Q.empty() && x--){
    int i = Q.top().second;
    Q.pop();
    int j = ExtractIndex(i);
    a[j] = b[j];
    CheckAndPush(i);
  }

  if(x > 0){
    return false;
  }

  if(y == 0){
    return true;
  }

  vector<int> v = GetRemaining(n);
  v.resize(min((int)v.size(), y + 1));

  if(v.size() < y){
    v.clear();
    return false;
  }

  if(v.size() == y && (b[v.front()] == b[v.back()])){
    v.clear();
    return false;
  }

  for(int i = 0; i < y; ++i){
    int j = (i + 1) % v.size();
    a[v[i]] = b[v[j]];
  }

  v.clear();
  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if(!Solve(n, x, y)){
      printf("NO\n");
    }
    else{
      printf("YES\n");
      for(int i = 1; i <= n; ++i){
        printf("%d ", a[i]);
      }
      printf("\n");
    }
  }
  return 0;
}