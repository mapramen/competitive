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
#define B 20
#define N (1 << B)

int a[N], dpOr[N], dpAnd[N];

void Count(int n){
  for(int i = 1; i <= n; ++i){
    ++dpAnd[a[i]];
    ++dpOr[a[i]];
  }

  for(int k = 0; k < B; ++k){
    for(int i = 0; i < N; ++i){
      if((i & (1 << k)) == 0){
        dpAnd[i] += dpAnd[(i ^ (1 << k))];
      }
      else{
        dpOr[i] += dpOr[(i ^ (1 << k))];
      }
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  Count(n);

  for(int i = 1; i <= n; ++i){
    int x = a[i];
    printf("%d %d %d\n", dpOr[x], dpAnd[x], n - dpOr[(x ^ (N - 1))]);
  }

  return 0;
}