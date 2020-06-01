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

void Solve(){
  int n, k;
  set<int> s;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s.insert(x);
  }

  if(s.size() > k){
    printf("-1\n");
    return;
  }

  for(int i = 1; i <= n && s.size() < k; ++i){
    s.insert(i);
  }

  printf("%d\n", n * k);
  for(int i = 1; i <= n; ++i){
    for(int x : s){
      printf("%d ", x);
    }
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