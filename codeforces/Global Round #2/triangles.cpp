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
#define N 300001

int a[N];
queue<int> Q;

void Add(int i){
  if(a[i]){
    Q.push(i);
  }
}

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int &y = a[i];
    while(!Q.empty() && y > 1){
      int j = Q.front();
      Q.pop();

      int &x = a[j];
      int z = min(2 * x, y) / 2;
      x -= z, y -= 2 * z;
      ans += z;

      Add(j);
    }
    ans += (y / 3);
    y %= 3;
    Add(i);
  }

  printf("%lld\n", ans);

  return 0;
}