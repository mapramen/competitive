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

priority_queue<int,vector<int>,greater<int>> Q;

int ExtractTop(){
  int x = Q.top();
  Q.pop();
  return x;
}

int main(){
  int m, n;

  scanf("%d%d", &m, &n);
  while(n--){
    int x;
    scanf("%d", &x);
    Q.push(x);
  }

  ll ans = 0;
  while(Q.size() > 1){
    int x = ExtractTop() + ExtractTop();
    ans += x;
    Q.push(x);
  }

  printf("%lld\n", ans);
  
  return 0;
}