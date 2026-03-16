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
#define MOD 1000000007

int a[N], T[N];

int ReadInput(){
  int n;
  map<int,int> M;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    M[a[i]] = 0;
  }

  int m = 0;
  for(auto it = M.begin(); it != M.end(); ++it){
    it->second = ++m;
  }

  for(int i = 1; i <= n; ++i){
    a[i] = M[a[i]];
  }

  return n;
}

void Update(int i, int val){
  for( ; i < N; i += (i & -i)){
    T[i] = (T[i] + val) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int main(){
  int n = ReadInput();

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int ansx = (1 + Query(a[i] - 1)) % MOD;
    ans = (ans + ansx) % MOD;
    Update(a[i], ansx);
  }

  printf("%d\n", ans);

  return 0;
}