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
#define N 101

int a[N];

int NumberOfInversePair(int x, int y){
  if(x <= y){
    return x * (x - 1) / 2;
  }

  return y * (x - y) + NumberOfInversePair(y, y);
}

double ProbabilityOfInversePair(int x, int y){
  return 1.0 * NumberOfInversePair(x, y) / (x * y);
}

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  double ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      ans += ProbabilityOfInversePair(a[i], a[j]);
    }
  }

  printf("%lf\n", ans);

  return 0;
}