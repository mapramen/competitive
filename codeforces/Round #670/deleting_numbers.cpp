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
#define N 100001

bool isPrime[N];

void Initialise(int n){
  for(int i = 2; i <= n; ++i){
    isPrime[i] = true;
  }

  for(int i = 2; i <= n; ++i){
    for(int j = 2 * i; j <= n; j += i){
      isPrime[j] = false;
    }
  }
}

void Print(char c, int i){
  printf("%c %d\n", c, i);
  fflush(stdout);
}

int Query(char c, int i){
  Print(c, i);
  int x;
  scanf("%d", &x);
  return x;
}

bool IsFactor(int i){
  Query('B', i);
  return Query('A', i);
}

int GetLargePrimeFactor(int l, int r, int x){
  for( ; !isPrime[l]; ++l);
  for( ; !isPrime[r]; --r);

  if(l > r){
    return 1;
  }

  int mid = l + (r - l) / 2;

  for(int i = l; i <= mid; ++i){
    if(!isPrime[i]){
      continue;
    }
    
    int q = Query('B', i);
    
    if(q == 2){
      return i;
    }

    if(q == 0){
      isPrime[i] = false;
    }
    else{
      --x;
    }
  }

  int y = Query('A', 1);

  if(y != x && l == r){
    return l;
  }

  return y != x ? GetLargePrimeFactor(l, mid, y) : GetLargePrimeFactor(mid + 1, r, y);
}

int Solve(int n){
  Initialise(n);
  
  for(int i = 2; i * i <= n; ++i){
    if(!isPrime[i]){
      continue;
    }
    Query('B', i);
  }

  vector<int> primeFactors;

  int p = 2;
  for( ; p * p <= n; ++p){
    if(!isPrime[p] || Query('A', p) == 0){
      continue;
    }
    primeFactors.push_back(p);
  }

  p = GetLargePrimeFactor(p, n, Query('A', 1));

  if(p != 1){
    primeFactors.push_back(p);
  }

  int ans = 1;
  for(int i: primeFactors){
    while(ans <= n / i && Query('A', i * ans)){
      ans *= i;
    }
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  Print('C', Solve(n));
  return 0;
}