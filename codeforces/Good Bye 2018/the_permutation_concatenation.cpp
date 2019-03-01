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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 998244353

int main(){
  ll n;
  cin >> n;
  ll p = 1, ans = 0;
  for(ll i = n; i > 1; --i){
    p = (p * i) % MOD;
    ans = (ans + p) % MOD;
  }
  ans = (n * p + MOD - ans) % MOD;
  cout << ans << '\n';
  return 0;
}