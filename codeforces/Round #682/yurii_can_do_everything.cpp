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

int BinarySearch(int n, int i, ll val){
  int x = i + 2, y = n, ans = n + 1;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(s[mid] >= val){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

ll Count(int n){
  ll ans = 0;

  for(int i = 1; i <= n; ++i){
    s[i] = a[i] + s[i - 1];
  }

  for(int i = 1; i <= n; ++i){
    int j = BinarySearch(n, i, s[i] + a[i]);
    if(j > n){
      continue;
    }

    ll sum = s[j - 1] - s[i - 1];
    for( ; j <= n; ++j){
      sum += a[j];
      if(sum > 4ll * a[i]){
        break;
      }

      if(2ll * (a[i] | a[j]) == sum && a[j] < a[i]){
        ++ans;
      }
    }
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = Count(n);

  reverse(a + 1, a + n + 1);
  ans += Count(n);

  printf("%lld\n", ans);

  return 0;
}