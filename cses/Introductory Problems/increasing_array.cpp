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
  int n;
  scanf("%d", &n);

  ll ans = 0;
  for(int i = 0, y = 0; i < n; ++i){
    int x;
    scanf("%d", &x);

    if(x < y){
      ans += (y - x);
    }
    else{
      y = x;
    }
  }

  printf("%lld\n", ans);

  return 0;
}