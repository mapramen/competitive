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

bool Solve(){
  string s;
  cin >> s;
  
  int k = 0, m = 0, n = s.size();
  for(auto c : s){
    k += (c == '.');
    m += (c == 'B');
  }

  return ((m <= n - 2) && (k <= m || m > 1));
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve() ? "Y" : "N");
  }
  return 0;
}
