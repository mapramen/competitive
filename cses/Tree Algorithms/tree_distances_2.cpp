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
#define N 200001

vector<vector<int>> adj(N);
int n, subtreeSize[N];
ll dpUp[N], dpDown[N];

void DownDFS(int i, int p){
  int sz = 1;
  ll ans = 0;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DownDFS(j, i);
    ans += (dpDown[j] + subtreeSize[j]);
    sz += subtreeSize[j];
  }

  dpDown[i] = ans;
  subtreeSize[i] = sz;
}

void UpDFS(int i, int p){
  ll ans = dpUp[i] - (n - subtreeSize[i]) - 1; 
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    ans += dpDown[j];
  }

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    dpUp[j] = ans - dpDown[j] + 2 * (n - subtreeSize[j]);
    UpDFS(j, i);
  }
}

int main(){
  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DownDFS(1, 0);
  UpDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%lld ", dpDown[i] + dpUp[i]);
  }
  printf("\n");

  return 0;
}