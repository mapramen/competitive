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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500005

int a[N], d[N], c[N];
ll prefixSum[N];
map< int, int > checkMap;

int DegreeParity(){
  int ans = 0;
  for(int i = 0; i < N; ++i){
    int j = i % 2;
    ans += j * a[i];
  }
  ans %= 2;
  return ans;
}

int Check(int m){
  if(checkMap.count(m) > 0){
    return checkMap[m];
  }

  ++a[m];
  int n = 0;
  for(int i = N - 1; i > -1; --i){
    int x = a[i];
    while(x--){
      d[++n] = i;;
    }
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    prefixSum[i] = d[i] + prefixSum[i - 1];
  }

  ll s = 0;
  int ans = 0;
  for(int i = n; i > 0; --i){
    s -= c[i + 1];
    c[i] += c[i + 1];

    if(prefixSum[i] > 1ll * i * (i - 1) + s){
      ans = (m >= d[i]) ? -1 : 1;
      break;
    }

    int j = min(i, d[i]);
    s += j;
    ++c[j];
  }

  --a[m];
  checkMap[m] = ans;

  return ans;
}

int BinarySearchLowerBound(){
  int parity = DegreeParity(), x = 0, y = (N - 5) / 2, ans = INT_MAX;
  while(x <= y){
    int mid = (x + y) / 2;
    int m = 2 * mid + parity;
    int check = Check(m);

    if(check == 0){
      ans = m, y = mid - 1;
    }
    else if(check < 0){
      y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int BinarySearchUpperBound(){
  int parity = DegreeParity(), x = 0, y = (N - 5) / 2, ans = INT_MAX;
  while(x <= y){
    int mid = (x + y) / 2;
    int m = 2 * mid + parity;
    int check = Check(m);

    if(check == 0){
      ans = m, x = mid + 1;
    }
    else if(check < 0){
      y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++a[i];
  }

  int l = BinarySearchLowerBound(), r = BinarySearchUpperBound();

  if(l == INT_MAX){
    printf("-1\n");
    return 0;
  }

  for(int i = l; i <= r; i += 2){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}