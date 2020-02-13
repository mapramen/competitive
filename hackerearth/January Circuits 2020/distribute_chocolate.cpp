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
  scanf("%d", &t);
  while(t--){
    ll s, n, ans;
    scanf("%lld%lld", &s, &n);
    
    if(s < n * (n + 1) / 2){
      ans = s;
    }
    else{
      ll x = (2 * s - n * (n - 1)) / (2 * n);
      ans = s - n * (2 * x + (n - 1)) / 2;
    }

    printf("%lld\n", ans);
  }
  return 0;
}