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

bool Check(int n, int m, int d){
  for(int i = 1, j = n - m + 1; i <= m; ++i, ++j){
    if(a[j] - a[i] < d){
      return false;
    }
  }
  return true;
}

int BinarySearch(int n, int d){
  int x = 0, y = n / 2, ans = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid, d)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int main(){
  int n, d;

  scanf("%d%d", &n, &d);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  sort(a + 1, a + n + 1);

  printf("%d\n", BinarySearch(n, d));

  return 0;
}