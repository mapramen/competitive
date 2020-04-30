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
  vector< pii > ans;

  int n;
  cin >> n;

  int lsb = -1, msb = -1, i = 0, isForward = 1;
  int s = -2;

  ans.push_back(make_pair(0, 0));

  if(n % 2 == 0){
    ans.push_back(make_pair(1, 0));
    ++s;
    ++i;
  }

  for(int k = 1; (1 << k) <= n; ++k){
    if(((1 << k) & n) == 0){
      continue;
    }

    for(++i; i < k; ++i){
      ans.push_back(make_pair(i, isForward ? 0 : i));
    }

    for(int j = isForward ? 0 : i, dj = isForward ? 1 : -1; j >= 0 && j <= i; j += dj){
      ans.push_back(make_pair(i, j));
    }

    isForward = 1 - isForward;
  }
}

int main(){
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k){
    cout << "Case #" << k << ":\n";
    Solve();
  }
  return 0;
}