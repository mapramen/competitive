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
#define B 19
#define M (1 << B)

char s[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int T[M], ans[M], prefixAns[2][M], suffixAns[2][M];

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  int x = T[k1], y = T[k2];

  if(x != -1 && x == y){
    T[k] = x;
  }
  else{
    T[k] = -1;
  }

  ans[k] = max(ans[k1], ans[k2]);
  for(int z = 0; z < 2; ++z){
    prefixAns[z][k] = prefixAns[z][k1] + ((x == z) ? max(0, prefixAns[z][k2]) : 0);
    suffixAns[z][k] = suffixAns[z][k2] + ((y == z) ? max(0, suffixAns[z][k1]) : 0);
    ans[k] = max(ans[k], suffixAns[z][k1] + prefixAns[z][k2]);
  }
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    ans[k] = 1;
    int x = s[l - 1] - '0';
    T[k] = x;
    prefixAns[x][k] = 1, suffixAns[x][k] = 1;
    prefixAns[1 - x][k] = -N, suffixAns[1 - x][k] = -N;
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void Update(int k, int l, int r, int i){
  if(i < l || r < i){
    return;
  }

  if(l == i && r == i){
    T[k] ^= 1;
    swap(prefixAns[0][k], prefixAns[1][k]);
    swap(suffixAns[0][k], suffixAns[1][k]);
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, i);
  Update(2 * k + 2, (l + r) / 2 + 1, r, i);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  scanf("%s", s);
  
  int n = strlen(s);
  BuildSegmentTree(0, 1, n);

  int q;
  scanf("%d", &q);
  while(q--){
    int i;
    scanf("%d", &i);
    Update(0, 1, n, i);
    printf("%d ", ans[0]);
  }
  printf("\n");

  return 0;
}