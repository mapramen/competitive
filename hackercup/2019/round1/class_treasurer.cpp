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
#define N 1000001
#define MOD 1000000007

int a[N], p[N];
char s[N];

void Initialise(){
  p[0] = 1;
  for(int i = 1; i < N; ++i){
    p[i] = (2 * p[i - 1]) % MOD;
  }
}

int Solve(){
  int n, m, ans = 0, c = 0;
  scanf("%d%d%s", &n, &m, s);

  for(int i = n; i > 0; --i){
    int x = s[i - 1] == 'A' ? 1 : -1;
    c = max(0, c - x);
    if(c > m){
      ans = (ans + p[i]) % MOD;
      c = max(0, c - 2);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }

  return 0;
}