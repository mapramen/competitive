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

int ModExp(int a, int n){
  int y = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      y = (1ll * a * y) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return y;
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d\n", ModExp(2, n));
  return 0;
}