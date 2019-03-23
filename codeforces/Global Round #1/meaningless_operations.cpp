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

int LeastPrimeFactor(int n){
  for(int i = 3; i * i <= n; i += 2){
    if(n % i == 0){
      return i;
    }
  }
  return n;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int x, ans;
    cin >> x;
    if(__builtin_popcount(x + 1) != 1){
      int k = 31 - __builtin_clz(x) + 1;
      ans = (1 << k) - 1;
    }
    else{
      ans = x / LeastPrimeFactor(x);
    }
    cout << ans << '\n';
  }
  return 0;
}