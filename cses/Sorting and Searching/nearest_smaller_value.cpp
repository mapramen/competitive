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

int a[N], ans[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  stack<int> S;
  S.push(0);

  for(int i = 1; i <= n; ++i){
    for(int x = a[i]; x <= a[S.top()]; S.pop());
    ans[i] = S.top();
    S.push(i);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");
  
  return 0;
}