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

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  string s;
  cin >> s;

  ll ans = 0;
  for(int n = s.size(), i = 0, c = 0; i <= n; ++i){
    if(i >= 3 && string(s, i - 3, 4) == "KICK"){
      ++c;
    }

    if(i >= 4 && string(s, i - 4, 5) == "START"){
      ans += c;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}