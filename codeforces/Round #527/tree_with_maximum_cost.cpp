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
#define N 200001

vector< vector<int> > adj(N);
int a[N];
ll sumDown[N], sumUp[N], dpDown[N], dpUp[N];

void DFS1(int i, int p = 0){
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    DFS1(j, i);
    sumDown[i] += sumDown[j];
    dpDown[i] += dpDown[j];
  }
  dpDown[i] += sumDown[i];
  sumDown[i] += a[i];
}

void DFS2(int i, int p = 0){
  dpUp[i] = dpUp[p] + max(0ll, dpDown[p] - dpDown[i] - sumDown[i]) + sumDown[1] - sumDown[i];
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    DFS2(j, i);
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS1(1);
  DFS2(1);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = max(ans, dpDown[i] + dpUp[i]);
  }

  printf("%lld\n", ans);

  return 0;
}