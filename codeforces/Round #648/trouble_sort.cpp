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

string Solve(){
  int n;
  bool isSorted = true;

  scanf("%d", &n);

  for(int i = 1, y = INT_MIN; i <= n; ++i){
    int x;
    scanf("%d", &x);
    isSorted = isSorted && (y <= x);
    y = x;
  }

  int s = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s += x;
  }

  bool ans = isSorted || (min(s, n - s) != 0);

  return ans ? "Yes" : "No";
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}