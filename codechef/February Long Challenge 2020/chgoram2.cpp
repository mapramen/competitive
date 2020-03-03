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
#define N 200001

vector< vector<int> > adj(N);
vector< vector<ll> > dpLeg(N), dpFork(N);
int isSuitable[N];

ll CollectAns(vector<ll> &a, vector<ll> &b){
  ll ans = 0;
  for(int i = (int)a.size() - 1, j = (int)b.size() - 1; i > -1 && j > -1; --i, --j){
    ans += a[i] * b[j];
  }
  return ans;
}

ll DFS(int i, int p){
  ll ans = 0;

  dpLeg[i].clear(), dpFork[i].clear();
  
  dpLeg[i].push_back(isSuitable[i]);
  dpFork[i].push_back(0);

  for(int j : adj[i]){
    if(j == p){
      continue;
    }

    ans += DFS(j, i);

    dpLeg[j].push_back(0), dpFork[j].pop_back();

    ans += CollectAns(dpLeg[i], dpFork[j]);
    ans += CollectAns(dpLeg[j], dpFork[i]);

    if(dpLeg[j].size() > dpLeg[i].size()){
      swap(dpLeg[i], dpLeg[j]);
    }

    if(dpFork[j].size() > dpFork[i].size()){
      swap(dpFork[i], dpFork[j]);
    }

    if(dpLeg[j].size() > dpFork[i].size()){
      int x = (int)dpLeg[j].size() - 1, y = (int)dpFork[i].size() - 1;
      
      dpFork[i].resize(dpLeg[j].size());
      
      for( ; y > -1; --x, --y){
        dpFork[i][x] = dpFork[i][y];
      }

      for( ; x > -1; --x){
        dpFork[i][x] = 0;
      }
    }

    for(int x = (int)dpFork[i].size() - 1, y = (int)dpLeg[i].size() - 1, z = dpLeg[j].size() - 1; z > -1; --x, --y, --z){
      dpFork[i][x] += dpLeg[i][y] * dpLeg[j][z];
      dpLeg[i][y] += dpLeg[j][z];
    }

    for(int x = (int)dpFork[i].size() - 1, y = (int)dpFork[j].size() - 1; y > -1; --x, --y){
      dpFork[i][x] += dpFork[j][y];
    }
  }

  adj[i].clear();

  return ans;
}

int TakeInput(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &isSuitable[i]);
  }

  return n;
}

ll Solve(){
  int n = TakeInput();
  ll ans = DFS(1, 0);
  return 6 * ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}