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
#define B 18

int c[N];
vector<int> a, b, basis;

bool CheckBasis(int m){
  a.clear(), b.clear(), basis.clear();

  for(int i = min(N - 1, (1 << m) - 1); i > 0; --i){
    if(c[i]){
      a.push_back(i);
      b.push_back(i);
    }
  }

  int n = a.size();

  for(int i = 0, k = m - 1; k > -1; ++i, --k){
    for(int j = i; j < n; ++j){
      if((a[j] & (1 << k))){
        swap(a[i], a[j]);
        swap(b[i], b[j]);
        break;
      }
    }

    if(i >= n || (a[i] & (1 << k)) == 0){
      basis.clear();
      --i;
      continue;
    }

    int x = a[i];
    for(int j = i + 1; j < n; ++j){
      if((a[j] & (1 << k))){
        a[j] ^= x;
      }
    }

    basis.push_back(b[i]);
  }

  return basis.size() == m;
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  for(int k = B; !CheckBasis(k); --k);
  
  int k = basis.size();
  vector<int> ans((1 << k));
  for(int i = 1; i < (1 << k); ++i){
    ans[i] = (i ^ (i >> 1));
  }

  for(int i = (1 << k) - 1; i > 0; --i){
    int j = __builtin_popcount((ans[i] ^ ans[i - 1]) - 1);
    ans[i] = basis[j];
  }

  for(int i = 1; i < (1 << k); ++i){
    ans[i] ^= ans[i - 1];
  }

  printf("%d\n", k);
  for(int i = 0; i < (1 << k); ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}