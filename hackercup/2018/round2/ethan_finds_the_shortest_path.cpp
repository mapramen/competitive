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

void Solve(){
  int n, k, ans = 0, m;

  cin >> n >> k;

  if(n > 2 && k > 3){
    ans = -k;
    m = min(n, k);
    for(int i = 1; i < m; ++i){
      ans += (k - i);
    }
  }

  printf("%d\n", ans);

  if(ans == 0){
    printf("1\n1 %d 1\n", n);
  }
  else{
    printf("%d\n", m);
    printf("%d %d %d\n", 1, n, k);
    for(int i = 1; i < m; ++i){
      printf("%d %d %d\n", i, i + 1 == m ? n : i + 1, k - i);
    }
  }
}

int main(){
  int t;

  cin >> t;
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }

  return 0;
}
