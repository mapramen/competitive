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
stack<int> S, P;

ll Update(int i, int x){
  int j = i;
  ll ans = 0;

  while(!S.empty() && S.top() >= x){
    j = P.top();
    ans = max(ans, 1ll * S.top() * (i - j));
    P.pop(), S.pop();
  }

  S.push(x), P.push(j);

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = max(ans, Update(i, a[i]));
  }

  ans = max(ans, Update(n + 1, 0));

  printf("%lld\n", ans);
  
  return 0;
}