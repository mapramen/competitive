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
#define MOD 998244353

ll a[N], b[N], c[N], d[N];
int p[N];

void Initialise(int n, int m){
  a[0] = 1, b[0] = 1, c[0] = 1, d[0] = 0;

  for(int i = 1; i <= n; ++i){
    a[i] = (m * b[i - 1]) % MOD;
    b[i] = ((m - 1) * b[i - 1]) % MOD;
    c[i] = (d[i - 1] + (m - 2) * c[i - 1]) % MOD;
    d[i] = ((m - 1) * c[i - 1]) % MOD;
  }
}

ll Solve(vector<int> v){
  ll ans = 1;

  v.push_back(0);
  for(int n = v.size() - 1, i = -1, j = 0, x = 0, y = 0; i < n; x = y, i = j){
    int k = 0;
    for(j = i + 1; j < n && v[j] == -1; ++j, ++k);
    y = v[j];

    int m1 = min(x, y), m2 = max(x, y), ansx = 1;

    if(m2 == 0){
      ansx = a[k];
    }
    else if(m1 == 0){
      ansx = b[k];
    }
    else if(m1 != m2){
      ansx = c[k];
    }
    else{
      ansx = d[k];
    }

    ans = (ans * ansx) % MOD;
  }

  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  for(int i = 3; i <= n; ++i){
    if(p[i] == p[i - 2] && p[i] != -1){
      printf("0\n");
      return 0;
    }
  }

  Initialise(n / 2, m);

  vector<int> v1, v2;
  for(int i = 1; i <= n; i += 2){
    v1.push_back(p[i]);
  }

  for(int i = 2; i <= n; i += 2){
    v2.push_back(p[i]);
  }

  int ans = (Solve(v1) * Solve(v2)) % MOD;

  printf("%d\n", ans);

  return 0;
}