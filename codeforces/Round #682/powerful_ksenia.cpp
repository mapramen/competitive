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
#define N 100001

int a[N];


int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int val = 0;
  for(int i = 1; i <= n; ++i){
    val ^= a[i];
  }

  if(n % 2 == 0 && val != 0){
    printf("NO\n");
    return 0;
  }

  n -= (n % 2 == 0);

  printf("YES\n");
  printf("%d\n", n - 2);

  for(int i = 1; i + 2 <= n; i += 2){
    printf("%d %d %d\n", i, i + 1, i + 2);
  }

  for(int i = 1; i + 2 < n; i += 2){
    printf("%d %d %d\n", i, i + 1, n);
  }

  return 0;
}