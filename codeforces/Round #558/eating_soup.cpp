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
#define N 1001

int a[N];

int main(){
  int n, m;

  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    a[i] = 1;
  }

  for(int i = 2; i <= n && m > 0; i += 2, --m){
    a[i] = 0;
  }

  for(int i = 1; i <= n && m > 0; i += 2, --m){
    a[i] = 0;
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    if(a[i] == 0){
      ++m;
      continue;
    }
    ans += (a[i - 1] == 0);
  }
  ans -= (a[1] == 1 && n > 1 && a[n] == 1);
  ans = max(1 * (m != n), ans);

  cout << ans << '\n';

  return 0;
}