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
#define MOD 1000000007
#define B 52

char s[N];
int a[N], freq[B];
ll fact[N], invFact[N], dp[N], ans[B][B];

int ModExp(int a, int n){
  ll x = a, y = 1;
  for( ; n; n /= 2){
    if(n % 2){
      y = (y * x) % MOD;
    }
    x = (x * x) % MOD;
  }
  return (int)y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

int TakeInput(){
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 1; i <= n; ++i){
    char c = s[i - 1];
    if('a' <= c && c <= 'z'){
      a[i] = c - 'a';
    }
    else{
      a[i] = c - 'A' + 26;
    }
    ++freq[a[i]];
  }
  return n;
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }

  invFact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = ((i + 1) * invFact[i + 1]) % MOD;
  }
}

void AddToKnapsack(int n, int x){
  if(x == 0){
    return ;
  }

  for(int i = n; i >= x; --i){
    dp[i] = (dp[i] + dp[i - x]) % MOD;
  }
}

void RemoveFromKnapsack(int n, int x){
  if(x == 0){
    return ;
  }

  for(int i = x; i <= n; ++i){
    dp[i] = (dp[i] + MOD - dp[i - x]) % MOD;
  }
}

void PreProcess(int n){
  ll w = fact[(n / 2)];
  w = (w * w) % MOD;
  for(int i = 0; i < B; ++i){
    w = (w * invFact[freq[i]]) % MOD;
  }

  dp[0] = 1;
  for(int i = 0; i < B; ++i){
    AddToKnapsack(n, freq[i]);
  }

  for(int i = 0; i < B; ++i){
    RemoveFromKnapsack(n, freq[i]);
    for(int j = i + 1; j < B; ++j){
      RemoveFromKnapsack(n, freq[j]);
      ans[i][j] = (2 * w * dp[(n / 2)]) % MOD;
      ans[j][i] = ans[i][j];
      AddToKnapsack(n, freq[j]);
    }
    ans[i][i] = (2 * w * dp[(n / 2)]) % MOD;
    AddToKnapsack(n, freq[i]);
  }
}

int main(){
  Initialise();

  int n = TakeInput();
  PreProcess(n);

  int q;
  scanf("%d", &q);
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    i = a[i], j = a[j];
    printf("%lld\n", ans[i][j]);
  }

  return 0;
}