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
#define N 2501

vector<tiii> edges;
int parent[N];
ll dp[N];

ll inf = 1E18;

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edges.push_back({i, j, k});
  }

  int x;
  for(int k = 1; k <= n; ++k){
    x = 0;
    for(auto edge: edges){
      auto [i, j, w] = edge;
      if(dp[i] + w < dp[j]){
        dp[j] = dp[i] + w;
        parent[j] = i;
        x = j;
      }
    }
  }

  if(x == 0){
    printf("NO\n");
    return 0;
  }

  for(int i = 1; i <= n; ++i){
    x = parent[x];
  }

  vector<int> ans;
  for(int i = x; ans.size() <= 1 || ans.back() != x; i = parent[i]){
    ans.push_back(i);
  }
  reverse(ans.begin(), ans.end());

  printf("YES\n");
  for(int x: ans){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}