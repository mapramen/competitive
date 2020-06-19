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

map<int,int> M;

int main(){
  int n;

  scanf("%d", &n);

  int ans = n;
  while(n--){
    int x;
    scanf("%d", &x);

    if(M.empty() || M.rbegin()->first <= x){
      ++M[x];
      continue;
    }

    auto it = M.upper_bound(x);
    if(it->second == 1){
      M.erase(it);
    }
    else{
      --(it->second);
    }

    ++M[x];
    --ans;
  }

  printf("%d\n", ans);

  return 0;
}