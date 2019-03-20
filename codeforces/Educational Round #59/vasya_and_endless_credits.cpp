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

#define pii pair< int, int>
#define pll pair< ll, ll>
#define tlll tuple< ll, ll, ll >
#define N 501

ll dp[N];

int main(){
  int n;
  vector< tlll > offers;

  cin >> n;
  for(int x = 1; x <= n; ++x){
    ll a, b, k;
    cin >> a >> b >> k;
    offers.push_back(make_tuple(b, a, k));
  }

  sort(offers.begin(), offers.end(), greater< tlll >());

  for(tlll offer : offers){
    ll b, a, k;
    tie(b, a, k) = offer;
    for(int i = n - 1; i >= 0; --i){
      dp[i + 1] = max(dp[i + 1], dp[i] + a - i * b);
      dp[i] = max(dp[i], dp[i] + a - k * b);
    }
  }

  ll ans = 0;
  for(int i = 0; i <= n; ++i){
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';

  return 0;
}