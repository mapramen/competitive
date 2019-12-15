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
  int q;
  cin >> q;
  while(q--){
    ll a, b, m;
    cin >> a >> b >> m;

    vector<ll> v{a, a};
    while(v.back() <= b){
      v.push_back(2 * v.back());
    }
    v.pop_back();

    int k = v.size() - 1;
    if((1ll << k) < b - a){
      cout << "-1\n";
      continue;
    }

    b -= a;
    vector<ll> u(v.size());
    for(int i = k - 1; i > -1; --i, b /= 2){
      u[i] = b % 2;
    }

    for(int i = 1; i <= k; ++i){
      v[i] = u[i];
      for(int j = 0; j < i; ++j){
        v[i] += v[j];
      }
    }

    cout << v.size() << ' ';
    for(auto x : v){
      cout << x << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}