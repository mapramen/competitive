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
#define N 100001

int c[N];
map<int,int> M;

void Increment(int i){
  if(i == 0){
    return;
  }
  ++M[i];
}

void Decrement(int i){
  if(i == 0){
    return;
  }
  
  --M[i];
  if(M[i] <= 0){
    M.erase(i);
  }
}

bool Check(int i){
  Decrement(i);
  Increment(i - 1);
  bool ans = M.size() < 2;
  Increment(i);
  Decrement(i - 1);
  return ans;
}

int main(){
  int n, ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    int y = ++c[x];
    Increment(y);
    Decrement(y - 1);

    if(M.size() > 2){
      continue;
    }

    vector<int> v;
    for(auto p : M){
      v.push_back(p.first);
    }

    for(int z : v){
      if(Check(z)){
        ans = i;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}