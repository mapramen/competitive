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
#define N 1001

vector< vector<int> > adj(N);
int d[N], parent[N];
const int inf = N;

int FarthestNode(int n, int s){
  for(int i = 1; i <= n; ++i){
    d[i] = inf;
  }

  d[s] = 0;
  parent[s] = 0;
  queue<int> Q;
  Q.push(s);

  while(!Q.empty()){
    s = Q.front();
    Q.pop();
    for(auto j : adj[s]){
      if(d[j] != inf){
        continue;
      }
      d[j] = 1 + d[s];
      parent[j] = s;
      Q.push(j);
    }
  }

  return s;
}

pii CalculateDiameterCenterPair(int n, int s){
  s = FarthestNode(n, s);
  s = FarthestNode(n, s);
  
  int diameter = d[s];
  for(int x = (diameter + 1) / 2; x; --x){
    s = parent[s];
  }

  return make_pair(diameter, s);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    d[i] = inf;
  }

  vector< pii > v;
  for(int i = 1; i <= n; ++i){
    if(d[i] != inf){
      continue;
    }
    v.push_back(CalculateDiameterCenterPair(n, i));
  }

  sort(v.begin(), v.end(), greater< pii >());

  int ans = v[0].first;
  vector<int> ansV{-1, -1};

  for(int i = 1; i < v.size(); ++i){
    int x = v[i].first;
    x = (x + 1) / 2;
    for(int j = 0; j < ansV.size(); ++j){
      if(x > ansV[j]){
        swap(x, ansV[j]);
      }
    }
    ans = max(ans, v[i].first);
  }

  ans = max(ans, (v[0].first + 1) / 2 + 1 + ansV[0]);
  ans = max(ans, ansV[0] + 2 + ansV[1]);

  printf("%d\n", ans);

  for(int i = 1; i < v.size(); ++i){
    printf("%d %d\n", v[0].second, v[i].second);
  }
  
  return 0;
}