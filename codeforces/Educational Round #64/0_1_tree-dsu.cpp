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

int parent[N][2], s[N][2];

int Find(int i, int c){
  return parent[i][c] == i ? i : parent[i][c] = Find(parent[i][c], c);
}

void Union(int i, int j, int c){
  i = Find(i, c), j = Find(j, c);
  if(i == j){
    return ;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j][c] = i;
  s[i][c] += s[j][c];
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int c = 0; c < 2; ++c){
      parent[i][c] = i;
      s[i][c] = 1;
    }
  }

  for(int x = 1; x < n; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    Union(i, j, k);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    if(parent[i][0] == i){
      ans += 1ll * s[i][0] * (s[i][0] - 1);
    }
    if(parent[i][1] == i){
      ans += 1ll * s[i][1] * (s[i][1] - 1);
    }
    ans += 1ll * (s[Find(i, 0)][0] - 1) * (s[Find(i, 1)][1] - 1);
  }

  printf("%lld\n", ans);

  return 0;
}