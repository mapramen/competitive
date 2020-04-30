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
#define N 100001

ll a[N], b[N];

void ReadPowers(int n, ll a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
}

int Solve(){
  int n;

  scanf("%d", &n);
  ReadPowers(n, a);
  ReadPowers(n, b);

  int ans = 0;
  for(int i = 1, j = 1; j <= n; ++i){
    for( ; j <= n && a[j] <= b[i]; ++j);
    ans += (j <= n);
    ++j;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}