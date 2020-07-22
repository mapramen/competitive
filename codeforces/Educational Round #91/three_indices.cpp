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
#define N 1002

int a[N], prefixMin[N], suffixMin[N];

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n;
    scanf("%d", &n);
  
    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    a[0] = a[n + 1] = INT_MAX;

    for(int i = 1, x = 0; i <= n; ++i){
      prefixMin[i] = x;
      if(a[i] < a[x]){
        x = i;
      }
    }

    for(int i = n, x = n + 1; i > 0; --i){
      suffixMin[i] = x;
      if(a[i] < a[x]){
        x = i;
      }
    }

    int i;
    for(i = 2; i < n; ++i){
      if(a[prefixMin[i]] >= a[i] || a[suffixMin[i]] >= a[i]){
        continue;
      }
      break;
    }

    if(i < n){
      printf("YES\n");
      printf("%d %d %d\n", prefixMin[i], i, suffixMin[i]);
    }
    else{
      printf("NO\n");
    }
  }

  return 0;
}