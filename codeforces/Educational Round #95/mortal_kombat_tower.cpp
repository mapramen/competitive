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
#define N 200002

int a[N];

int Solve(){
  int n;
  
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int meNext = 0, meNextNext = 0;
  int friendNext = 0, friendNextNext = 0;

  a[n + 1] = 0;
  for(int i = n; i > 0; --i){
    int meCurrent = min(friendNext, friendNextNext);
    int friendCurrent = min(a[i] + meNext, a[i] + a[i + 1] + meNextNext);

    meNextNext = meNext, meNext = meCurrent;
    friendNextNext = friendNext, friendNext = friendCurrent;
  }

  return friendNext;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}