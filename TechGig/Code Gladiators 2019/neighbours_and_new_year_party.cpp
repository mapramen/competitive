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
#define N 10005

int a[N], dp[N], nxt[N];

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n;
    map< int, int > M;
    
    scanf("%d", &n);
    for(int i = n; i > 0; --i){
      scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; ++i){
      a[i] = max(0, a[i]);
      dp[i] = 0;
    }

    int x = 0, k = n + 2;
    for(int i = n; i >= 0; --i){
      dp[i] = a[i] + x;
      nxt[i] = k;
      if(x < dp[i + 1] || (x == dp[i + 1] && a[k] < a[i + 1])){
        x = dp[i + 1];
        k = i + 1;
      }
    }

    for( ; k <= n; k = nxt[k]){
      printf("%d", a[k]);
    }
    printf("\n");
  }

  return 0;
}