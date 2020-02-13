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
    int n;
    scanf("%d", &n);

    int ans = n;
    while(n > 0){
      int x = (n & -n);
      if(__builtin_popcount(x - 1) > __builtin_popcount(ans)){
        ans = x - 1;
      }
      n -= x;
    }

    cout << ans << '\n';
  }
  return 0;
}