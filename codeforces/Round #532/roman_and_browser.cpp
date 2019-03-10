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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N];

int main(){
  int n, k, s = 0;

  cin >> n >> k;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    s += a[i];
  }

  int ans = 0;
  for(int i = 1; i <= k; ++i){
    int ansx = s;
    for(int j = i; j <= n; j += k){
      ansx -= a[j];
    }
    ans = max(ans, abs(ansx));
  }

  cout << ans << '\n';

  return 0;
}