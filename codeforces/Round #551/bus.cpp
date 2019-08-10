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
  int n, m, ans, x = INT_MAX;
  
  cin >> n >> m;
  
  for(int i = 1; i <= n; ++i){
    int s, d;
    cin >> s >> d;
    int y = (m - s + d - 1) / d;
    y = s + d * max(0, y);
    if(y < x){
      x = y, ans = i;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}