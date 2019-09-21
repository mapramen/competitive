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

int main(){
  int t;

  cin >> t;
  while(t--){
    int n;
    set<ll> S;

    cin >> n;
    while(n--){
      ll x;
      cin >> x;
      S.insert(x);
    }
    
    ll ans = 1ll * (*S.begin()) * (*S.rbegin());

    for(ll i = 2; i * i <= ans; ++i){
      if(ans % i == 0){
        if(S.count(i) == 0 || S.count(ans / i) == 0){
          ans = -1;
          break;
        }
        S.erase(i);
        S.erase(ans / i);
      }
    }

    if(!S.empty()){
      ans = -1;
    }

    cout << ans << '\n';
  }

  return 0;
}