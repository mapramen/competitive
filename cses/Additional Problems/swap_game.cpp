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
#include <unordered_map>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3
#define N (B * B)

vector<pii> dmoves{{-1, 0}, {0, -1}};
vector<pii> edges;
queue<int> Q;
unordered_map<int,int> d;

int GetMappedValue(int x, int y){
  return x * B + y;
}

int GetMappedValue(vector<int> &v){
  int ans = 0;
  for(int x: v){
    ans = (N + 1) * ans + x;
  }
  return ans;
}

void FillVectorValue(int x, vector<int> &v){
  for(int i = N - 1; i > -1; --i, x /= (N + 1)){
    v[i] = x % (N + 1);
  }
}

int Initialise(){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      const int i = GetMappedValue(x, y);
      for(pii dmove: dmoves){
        const int nx = x + dmove.first, ny = y + dmove.second;
        if(nx < 0 || ny < 0 || nx >= B || ny >= B){
          continue;
        }
        edges.push_back({i, GetMappedValue(nx, ny)});
      }
    }
  }

  vector<int> v;
  for(int i = 1; i <= N; ++i){
    v.push_back(i);
  }

  return GetMappedValue(v);
}

void CheckAndPush(vector<int> &v, int x){
  int i = GetMappedValue(v);
  auto it = d.find(i);
  if(it != d.end()){
    return;
  }

  d[i] = x;
  Q.push(i);
}

int main(){
  int t = Initialise();

  vector<int> v;
  for(int x = 1; x <= N; ++x){
    int i;
    scanf("%d", &i);
    v.push_back(i);
  }

  CheckAndPush(v, 0);

  while(d.count(t) == 0){
    int s = Q.front();
    Q.pop();

    int dx = 1 + d[s];
    FillVectorValue(s, v);

    for(pii edge: edges){
      auto [i, j] = edge;
      swap(v[i], v[j]);
      CheckAndPush(v, dx);
      swap(v[i], v[j]);
    }
  }

  printf("%d\n", d[t]);
  
  return 0;
}