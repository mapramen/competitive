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
#define MOD 1000000007

int ModExp(int a, int n, int mod){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * a * ans) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans % mod;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", ModExp(a, ModExp(b, c, MOD - 1), MOD));
  }
  return 0;
}