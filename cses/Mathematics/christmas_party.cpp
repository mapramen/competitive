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
#define MOD 1000000007

int main(){
  int n;
  cin >> n;

  int ans = 1;
  for(int i = 1, x = -1; i <= n; ++i, x = -x){
    ans = (1ll * i * ans + MOD + x) % MOD;
  }
  
  cout << ans << '\n';
  
  return 0;
}