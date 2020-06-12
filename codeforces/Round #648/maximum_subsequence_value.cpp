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
#define N 501

ll a[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      for(int k = j; k <= n; ++k){
        ans = max(ans, a[i] | a[j] | a[k]);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}