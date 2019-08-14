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
#define N 2001

int a[N], b[N], dp[N];
vector<int> v;

void Initialise(int n, int m, int k){
  priority_queue<int> Q;
  
  while(n--){
    int x;
    scanf("%d", &x);
    Q.push(x);
    if(Q.size() > k){
      Q.pop();
    }
  }

  while(m--){
    int x, y;
    scanf("%d%d", &x, &y);
    if(x > k){
      continue;
    }
    b[x] = max(b[x], y);
  }

  for(int i = k; i; --i, Q.pop()){
    a[i] = Q.top();
  }

  for(int i = 1; i <= k; ++i){
    a[i] += a[i - 1];
  }

  for(int i = 1; i <= k; ++i){
    if(i && b[i] == 0){
      continue;
    }
    b[i] = i - b[i];
    v.push_back(i);
  }
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);
  Initialise(n, m, k);

  n = k;
  for(int i = 1; i <= n; ++i){
    int &val = dp[i];
    val = a[i];

    for(int j : v){
      if(j > i){
        break;
      }
      int cost = a[i] - a[i - b[j]];
      val = min(val, dp[i - j] + cost);
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}