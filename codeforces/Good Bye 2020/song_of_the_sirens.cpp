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
#define B 26
#define N 100001
#define MOD 1000000007

char S[10 * N];
int c[B], p[N], sum[B][N], bSize;
string a, b, s, t;
vector<int> f;

string ReadString(){
  scanf("%s", S);
  return string(S);
}

void InitialiseSum(int sum[], char c){
  int n = t.size();
  for(int i = 1, x = 0; i <= n; ++i){
    x = (2 * x + (t[i - 1] == c)) % MOD;
    sum[i] = x;
  }
}

void Initialise(){
  int n = t.size();

  p[0] = 1;
  for(int i = 1, x = 1; i <= n; ++i){
    x = (2 * x) % MOD;
    p[i] = x;
  }

  for(int k = 0; k < B; ++k){
    InitialiseSum(sum[k], 'a' + k);
  }
}

int NextState(int i, char c, int &cnt){
  while(i != 0 && b[i] != c){
    i = f[i];
  }
  
  i += (b[i] == c);
  
  if(i == bSize){
    ++cnt;
    i = f[i];
  }
  
  return i;
}

void InitialiseKMP(){
  int n = b.size(), k = 0, ans = 0;
  f.resize(n + 1);

  bSize = b.size();
  for(int i = 2; i <= n; ++i){
    k = NextState(k, b[i - 1], ans);
    f[i] = k;
  }
}

int GetCost(int &k, char c){
  int n = a.size(), ans = 0;
  k = NextState(k, c, ans);

  for(int i = 1; i <= n; ++i){
    k = NextState(k, a[i - 1], ans);
  }

  return ans;
}

int PreProcess(bool skipCostCalculation){
  InitialiseKMP();

  int k = 0;
  int baseAns = GetCost(k, '$');

  if(skipCostCalculation){
    return baseAns;
  }

  for(int i = 0; i < B; ++i){
    int ki = k;
    c[i] = GetCost(ki, 'a' + i) - baseAns;
  }

  return baseAns;
}

int Solve(){
  int n, m = 0;

  scanf("%d", &n);
  b = ReadString();

  a = s;

  while(m < n && a.size() < b.size()){
    a = a + string(1, t[m]) + a;
    ++m;
  }

  if(m == n){
    return PreProcess(true);
  }

  int ans = (1ll * p[n - m] * PreProcess(false)) % MOD;

  for(int i = 0, j = n - 1; i < m; ++i, --j){
    int k = t[i] - 'a';
    ans = (ans - 1ll * p[j] * c[k]) % MOD;
  }

  for(int k = 0; k < B; ++k){
    ans = (ans + 1ll * sum[k][n] * c[k]) % MOD;
  }

  return (MOD + ans) % MOD;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);
  
  s = ReadString();
  t = ReadString();

  Initialise();

  while(q--){
    printf("%d\n", Solve());
  }

  return 0;
}