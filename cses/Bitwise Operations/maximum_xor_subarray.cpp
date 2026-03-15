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
#define B 30

int T[2][(N * B)], nxt;

void Add(int x){
  int i = 0;
  for(int j = B - 1; j > -1; --j){
    int k = (x & (1 << j)) > 0;
    if(T[k][i] == 0){
      T[k][i] = ++nxt;
    }
    i = T[k][i];
  }
}

int Query(int x){
  int i = 0, ans = 0;
  for(int j = B - 1; j > -1; --j){
    int k = (x & (1 << j)) > 0;
    if(T[1 - k][i] != 0){
      ans += (1 << j);
      i = T[1 - k][i];
    }
    else{
      i = T[k][i];
    }
  }
  return ans;
}

int main(){
  int n, xorSum = 0;

  scanf("%d", &n); 
  Add(xorSum);

  int ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    xorSum ^= x;
    ans = max(ans, Query(xorSum));
    Add(xorSum);
  }

  printf("%d\n", ans);

  return 0;
}