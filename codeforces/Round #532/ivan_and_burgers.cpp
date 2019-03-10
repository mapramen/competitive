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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 20
#define N 500002

int a[N], basis[N][B], basisIndex[N][B];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = n; i > 0; --i){
    for(int k = 0; k < B; ++k){
      basis[i][k] = basis[i + 1][k];
      basisIndex[i][k] = basisIndex[i + 1][k];
    }

    int x = a[i], j = i;
    for(int k = B - 1; k > -1; --k){
      if((x & (1 << k)) == 0){
        continue;
      }
      if(basis[i][k] == 0){
        basis[i][k] = x;
        basisIndex[i][k] = j;
        break;
      }
      if(j < basisIndex[i][k]){
        swap(x, basis[i][k]);
        swap(j, basisIndex[i][k]);
      }
      x ^= basis[i][k];
    }
  }

  int q;
  scanf("%d", &q);
  while(q--){
    int i, j, ans = 0;
    scanf("%d%d", &i, &j);
    for(int k = B - 1; k > -1; --k){
      if(basisIndex[i][k] <= j){
        ans = max(ans, ans ^ basis[i][k]);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}