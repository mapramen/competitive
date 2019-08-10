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

vector<ll> a, C, A, B;

void Add(ll t, ll a, ll b){
  C.push_back(t);
  A.push_back(a);
  B.push_back(b - a * (t - 1));
}

ll Query(ll t){
  int i = prev(upper_bound(C.begin(), C.end(), t)) - C.begin();
  return A[i] * t + B[i];
}

void PreProcess(){
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  for(int i = 0; i < a.size() - 1; ++i){
    a[i] = a[i + 1] - a[i];
  }
  a.pop_back();
  sort(a.begin(), a.end());

  ll m = a.size() + 1;
  Add(0, m, 0);

  for(int i = 0, n = a.size(); i < n; ){
    int j;
    for(j = i; j < n && a[j] == a[i]; ++j, --m);
    Add(a[i], m, Query(a[i] - 1));
    i = j;
  }
}

int main(){
  int n, q;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    a.push_back(x);
  }

  PreProcess();

  scanf("%d", &q);
  while(q--){
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld ", Query(r - l));
  }
  printf("\n");

  return 0;
}