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

void Solve(){
  int n, m;

  cin >> n >> m;

  cout << (n - 1) * (m - 1) << '\n';
  for( ; n > 1; --n){
    for(int i = 1; i < m; ++i){
      printf("%d %d\n", n, n * (m - 1) - i);
    }
  }
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ": ";
    Solve();
  }
  return 0;
}