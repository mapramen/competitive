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
#define N 200001

int a[N];
map<ll,int> M{{0ll, 1}};

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll s = 0, ans = 0;
  for(int i = 1; i <= n; ++i){
    s += a[i];
    auto it = M.find(s - m);
    if(it != M.end()){
      ans += it->second;
    }
    ++M[s];
  }

  printf("%lld\n", ans);

  return 0;
}