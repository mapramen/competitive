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
#define MOD 1000000007

int a[N], t[N], c[N];
ll fact[N], inv_fact[N];
stack<int> S;

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = 716327852;
  for(int i = N - 2; i >= 0; --i){
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
  }
}

ll nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0ll;
  }

  ll q = (inv_fact[r] * inv_fact[n - r]) % MOD;
  return (fact[n] * q) % MOD;
}

int Read(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  return n;
}

void Reset(int n){
  while(!S.empty()){
    S.pop();
  }

  for(int i = 1; i <= n; ++i){
    c[i] = 0;
    t[i] = 0;
  }
}

void AddChild(int i, int j){
  if(j == -1){
    return;
  }
  t[i] += (1 + t[j]);
  c[i] = 1 + t[j];
}

int Relax(int n){
  int y = -1;
  while(n < S.size()){
    AddChild(S.top(), y);
    y = S.top();
    S.pop();
  }
  return y;
}

int Compute(int n){
  Reset(n);

  for(int i = 1; i <= n; ++i){
    int x = a[i] - 1;
    if(S.size() < x){
      return 0;
    }

    AddChild(i, Relax(x));
    S.push(i);
  }

  Relax(0);

  ll ans = 1;
  for(int i = 1; i <= n; ++i){
    ans = (ans * nCr(t[i], c[i])) % MOD;
  }

  return ans;
}

int Solve(){
  int n = Read();
  return Compute(n);
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }

  return 0;
}