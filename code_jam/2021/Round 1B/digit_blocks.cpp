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
#define pvi pair<vector<int>,int>
#define pdi pair<double,int>
#define T 50
#define N 20
#define B 15

ll p[B];
unordered_map<string,pdi> M;

pdi GetStateValue(vector<int> &, int);
pdi GetActionValueWithMove(vector<int> &, int i, int d);

void Initialise(){
  ll x = 1;
  for(int i = 0; i < B; ++i){
    p[i] = x;
    x *= 10;
  }
}

void PushToTowerHeight(vector<int> &c, int i){
  ++c[i + 1], --c[i];
}

void RemoveFromTowerHeight(vector<int> &c, int i){
  --c[i], ++c[i - 1];
}

pdi GetActionValueWithMove(vector<int> &c, int i, int d){
  if(c[i] == 0){
    return {1.0 * LLONG_MIN, i};
  }

  PushToTowerHeight(c, i);
  double ans = d * p[i] + GetStateValue(c, -1).first;
  RemoveFromTowerHeight(c, i + 1);
  
  return {ans, i};
}

string GetStateHash(vector<int> &c, int d){
  string ans;
  c.push_back(d);
  for(int x: c){
    for(char a: to_string(x)){
      ans.push_back(a);
    }
    ans.push_back(',');
  }
  c.pop_back();
  return ans;
}

pdi GetStateValue(vector<int> &c, int d){
  string t = GetStateHash(c, d);
  auto it = M.find(t);

  if(it != M.end()){
    return it->second;
  }

  double score = 0;
  int move = -1;
  
  if(d == -1){
    for(int d = 0; d < 10; ++d){
      score += GetStateValue(c, d).first;
    }
    score /= 10;
  }
  else{
    vector<pdi> v;
    v.push_back(GetActionValueWithMove(c, B - 1, d));
    v.push_back(GetActionValueWithMove(c, B - 2, d));
    
    for(int i = B - 3; i > -1; --i){
      if(c[i] != 0){
        v.push_back(GetActionValueWithMove(c, i, d));
        break;
      }
    }

    sort(v.begin(), v.end());
    tie(score, move) = v.back();
  }

  M[t] = {score, move};
  return {score, move};
}

void Solve(){
  vector<vector<int>> heightTowers(B + 1);  
  vector<int> c(B + 1);
  c[0] = N;

  for(int i = 1; i <= N; ++i){
    heightTowers[0].push_back(i);
  }

  for(int x = 0, d; x < N * B; ++x){
    scanf("%d", &d);
    int h = GetStateValue(c, d).second;
    PushToTowerHeight(c, h);

    int i = heightTowers[h].back();
    heightTowers[h].pop_back();
    heightTowers[h + 1].push_back(i);

    printf("%d\n", i);
    fflush(stdout);
  }
}

int main(){
  int t, n, b;
  ll p;
  scanf("%d%d%d%lld", &t, &n, &b, &p);

  Initialise();
  while(t--){
    Solve();
  }

  return 0;
}