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
#define N 5001

int l[N], r[N], c[N], p[N];

void Update(int l, int r, int x){
  for(int i = l; i <= r; ++i){
    c[i] += x;
  }
}

void InitialisePrefixSum(int n){
  for(int i = 1; i <= n; ++i){
    p[i] = (c[i] == 1) + p[i - 1];
  }
}

int main(){
  int n, q;

  cin >> n >> q;
  for(int i = 1; i <= q; ++i){
    cin >> l[i] >> r[i];
  }

  for(int i = 1; i <= q; ++i){
    Update(l[i], r[i], 1);
  }

  int ans = 0;
  for(int i = 1; i <= q; ++i){
    Update(l[i], r[i], -1);
    InitialisePrefixSum(n);
    int ansx = INT_MIN;
    for(int j = i + 1; j <= q; ++j){
      ansx = max(ansx, - (p[r[j]] - p[l[j] - 1]));
    }
    for(int j = 1; j <= n; ++j){
      ansx += (c[j] > 0);
    }
    Update(l[i], r[i], 1);
    ans = max(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}