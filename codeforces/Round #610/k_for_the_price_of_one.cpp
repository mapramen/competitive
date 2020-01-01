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
#define N 200001

int a[N];

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n, p, k;

    scanf("%d%d%d", &n, &p, &k);

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);

    for(int i = 2; i < k; ++i){
      a[i] += a[i - 1];
    }

    for(int i = k; i <= n; ++i){
      a[i] += a[i - k];
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
      if(a[i] <= p){
        ans = i;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}