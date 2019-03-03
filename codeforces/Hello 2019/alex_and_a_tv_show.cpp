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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 7001
#define N 100001

bitset<M> a[N], b[M], d[M];

void Initialise(){
  for(int i = 1; i < M; ++i){
    for(int j = i; j < M; j += i){
      d[j].set(i);
    }
  }

  for(int i = M - 1; i > 0; --i){
    b[i].set(i);
    for(int j = i + i; j < M; j += i){
      b[i] ^= b[j];
    }
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);
  Initialise();

  while(q--){
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if(t == 1){
      a[x] = d[y];
    }
    else if(t == 2){
      int z;
      scanf("%d", &z);
      a[x] = a[y] ^ a[z];
    }
    else if(t == 3){
      int z;
      scanf("%d", &z);
      a[x] = a[y] & a[z];
    }
    else{
      int ans = (a[x] & b[y]).count();
      printf("%d", ans % 2);
    }
  }
  printf("\n");
  return 0;
}