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
ll s[N];
deque<int> Q;

void Add(int i){
  if(i < 0){
    return;
  }

  while(!Q.empty() && s[Q.back()] >= s[i]){
    Q.pop_back();
  }
  Q.push_back(i);
}

void Remove(int i){
  if(i < 0 || i != Q.front()){
    return;
  }
  Q.pop_front();
}

int main(){
  int n, l, r;

  scanf("%d%d%d", &n, &l, &r);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = LLONG_MIN;
  for(int i = 1; i <= n; ++i){
    Add(i - l);
    Remove(i - r - 1);

    s[i] = s[i - 1] + a[i];

    if(Q.empty()){
      continue;
    }

    ans = max(ans, s[i] - s[Q.front()]);
  }
  
  printf("%lld\n", ans);

  return 0;
}