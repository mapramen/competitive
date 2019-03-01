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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll n;
set<ll> S;

void AddToSet(ll d){
  ll x = (n * (n / d - 1)) / 2 + (n / d);
  S.insert(x);
}
int main(){
  cin >> n;
  for(ll i = 1; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    AddToSet(i);
    AddToSet(n / i);
  }
  for(auto x : S){
    printf("%lld ", x);
  }
  printf("\n");
  return 0;
}