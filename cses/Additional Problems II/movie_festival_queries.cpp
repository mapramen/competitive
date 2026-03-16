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
#define M 1000001
#define N 200001
#define LOGN 18

int T[LOGN][M + 1];

void PreProcess(){
  for(int i = M - 1; i > 0; --i){
    T[0][i] = min(T[0][i], T[0][i + 1]);
  }

  for(int k = 1; k < LOGN; ++k){
    for(int i = 1; i <= M; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }
}

int Query(int i, int j){
  int ans = 0;
  for(int k = LOGN - 1; k > -1; --k){
    if(T[k][i] <= j){
      ans += (1 << k);
      i = T[k][i];
    }
  }
  return ans;
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= M; ++i){
    T[0][i] = M;
  }

  while(n--){
    int i, j;
    scanf("%d%d", &i, &j);
    T[0][i] = min(T[0][i], j);
  }

  PreProcess();

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", Query(i, j));
  }

  return 0;
}