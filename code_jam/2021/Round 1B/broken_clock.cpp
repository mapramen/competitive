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
#define NANOSECONDS_IN_SEC 1000000000
#define SECS_IN_MIN 60
#define MINS_IN_HR 60

ll TICKS_IN_CIRCLE = 360ll * 12 * 10000000000ll;
ll MAX_NS = 12 * 60 * 60 * 1000000000ll;

vector<ll> GetHandAngles(ll ns){
  ll sa = (720 * ns) % TICKS_IN_CIRCLE;
  ll ma = (12 * ns) % TICKS_IN_CIRCLE;
  ll ha = (ns) % TICKS_IN_CIRCLE;
  return {ha, ma, sa};
}

bool Check(vector<ll> &v, vector<ll> &u){
  for(int i = 0; i < 3; ++i){
    if((TICKS_IN_CIRCLE + v[i] - v[0]) % TICKS_IN_CIRCLE != (TICKS_IN_CIRCLE + u[i] - u[0]) % TICKS_IN_CIRCLE) {
      return false;
    }
  }
  return true;
}

bool Check(vector<ll> &v, ll ns){
  vector<ll> u = GetHandAngles(ns);
  sort(u.begin(), u.end());

  do
  {
    if(Check(v, u)){
      return true;
    }
  } while (next_permutation(u.begin(), u.end()));

  return false;
}

ll GetTime(vector<ll> &v){
  ll a = v[0], b = v[1], c = v[2];

  for(int x = 0; x <= 1; ++x){
    for(int y = 0; y <= 12; ++y){
      ll t = (y - x) * TICKS_IN_CIRCLE + b - a;

      if(t < 0 || t % 11 != 0){
        continue;
      }

      t /= 11;
      if(Check(v, t)){
        return t;
      }
    }
  }

  return -1;
}

void Solve(){
  ll a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  vector<ll> v{a, b, c};
  sort(v.begin(), v.end());

  ll t = -1;
  do
  {
    t = GetTime(v);
  } while (t < 0 && next_permutation(v.begin(), v.end()));
  
  ll ns = t;
  ll s = ns / NANOSECONDS_IN_SEC;
  ll m = s / SECS_IN_MIN;
  ll h = m / MINS_IN_HR;

  printf("%lld %lld %lld %lld\n", h, m % MINS_IN_HR, s % SECS_IN_MIN, ns % NANOSECONDS_IN_SEC);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}