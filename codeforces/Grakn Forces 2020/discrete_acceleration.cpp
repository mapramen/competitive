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
#define N 100002

int a[N], b[N];

double Distance(int a[], int n, double t){
  double ans = 0, v = 1;
  for(int i = 1; i <= n; ++i, ++v){
    double d = a[i] - a[i - 1];
    double tx = min(t, d / v);
    t -= tx;
    ans += v * tx;
  }
  return ans;
}

bool Check(int n, int l, double t){
  return Distance(a, n, t) + Distance(b, n, t) >= l;
}

double BinarySearch(int n, int l){
  double x = 0, y = 1E9;
  for(int iter = 0; iter < 100; ++iter){
    double mid = (x + y) / 2;
    if(Check(n, l, mid)){
      y = mid;
    }
    else{
      x = mid;
    }
  }
  return (x + y) / 2;
}

double Solve(){
  int n, l;
  scanf("%d%d", &n, &l);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  a[n + 1] = l;

  for(int i = 0; i <= n + 1; ++i){
    b[i] = l - a[n - i + 1];
  }

  return BinarySearch(n + 1, l);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.9lf\n", Solve());
  }
  return 0;
}