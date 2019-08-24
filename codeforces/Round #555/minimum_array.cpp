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

int a[N];
map<int,int> M;

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++M[x];
  }

  for(int i = 1; i <= n; ++i){
    int x = (n - a[i]) % n;
    
    auto it = M.lower_bound(x);
    if(it == M.end()){
      it = M.begin();
    }

    a[i] = (a[i] + it->first) % n;
    
    --(it->second);
    if(it->second == 0){
      M.erase(it);
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}