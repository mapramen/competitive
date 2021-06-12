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

void Solve(){
  int n;
  scanf("%d", &n);

  bool neg = false;
  while(n--){
    int x;
    scanf("%d", &x);
    neg = neg || (x < 0);
  }

  if(neg){
    printf("NO\n");
    return;
  }

  printf("YES\n101\n");
  for(int i = 0; i <= 100; ++i){
    printf("%d ", i);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}