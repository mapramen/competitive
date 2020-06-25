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

int Sum(ll n){
  n %= MOD;
  return ((1ll * n * (n + 1)) / 2) % MOD;
}

int Sum(ll l, ll r){
  return (MOD + Sum(r) - Sum(l - 1)) % MOD;
}

int main(){
  ll n;

  cin >> n;

  int ans = n % MOD;
  for(ll i = 1; i != n; i = n / (n / (i + 1))){
    ans = (ans + 1ll * i * Sum(n / (i + 1) + 1, n / i)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}