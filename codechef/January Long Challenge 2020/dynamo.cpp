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

ll Query(ll x){
  cout << x << '\n';
  fflush(stdout);
  cin >> x;
  return x;
}

int main(){
  int t;
  cin >> t;
  
  while(t--){
    ll n = 1, b;
    cin >> b;
    while(b--){
      n *= 10;
    }

    ll s;
    cin >> s;
    s += 2 * n;

    for(int i = 0; i < 3; ++i){
      s = Query(s);
      s = n - s;
    };
  }

  return 0;
}