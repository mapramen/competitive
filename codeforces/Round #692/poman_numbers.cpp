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
#define B 26

int a[B];

bool Solve(){
  int n;
  string s;
  ll T;

  cin >> n >> T >> s;

  T = -T;
  T -= (1 << (s[n - 2] - 'a'));
  T += (1 << (s[n - 1] - 'a'));

  for(int i = 0; i < n - 2; ++i){
    ++a[s[i] - 'a'];
  }

  for(int i = 0; i < B; ++i){
    T += a[i] * (1ll << i);
  }

  if(T < 0 || T % 2 != 0){
    return false;
  }

  T /= 2;

  ll c = 0, k = 1;
  for(int i = 0; i < B || c > 0; ++i, k <<= 1, c /= 2){
    if(i < B){
      c += a[i];
    }

    if((T & k) != 0){
      if(c == 0){
        return false;
      }
      T -= k;
      --c;
    }
  }

  return T == 0;
}

int main(){
  cout << (Solve() ? "Yes" : "No") << '\n';
  return 0;
}