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
#define N 10001

int a[N];

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for(int i = 1; i <= n; ){
    int k = a[i];
    for(int j = i; j <= k; k = max(k, a[j]), ++j);
    i = k + 1;
    ++ans;
  }

  printf("%d\n", ans);
  
  return 0;
}