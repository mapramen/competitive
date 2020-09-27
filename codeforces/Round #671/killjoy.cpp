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

int Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  int c = 0, s = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    if(x == m){
      ++c;
    }
    s += x;
  }

  if(c == n){
    return 0;
  }

  if(s == n * m || c != 0){
    return 1;
  }

  return 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}