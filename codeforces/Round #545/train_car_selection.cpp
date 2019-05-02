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

ll bSum = 0, sSum = 0;
stack<ll> X, L, B, S;

void Add(ll x, ll l, ll b, ll s){
  X.push(x);
  L.push(l);
  B.push(b);
  S.push(s);
}

void Add(ll x, ll l){
  Add(x, l, bSum, sSum);
}

void Reset(ll n){
  while(!L.empty()){
    n += L.top();
    X.pop();
    L.pop();
    B.pop();
    S.pop();
  }
  Add(1, n);
}

bool PopFromStack(ll &x, ll &y, ll &l, ll &b, ll &s){
  if(X.empty()){
    return false;
  }
  x = X.top(), l = L.top(), b = B.top(), s = S.top();
  y = (bSum - b) + (sSum - s) * (x - 1);
  X.pop(), L.pop(), B.pop(), S.pop();
  return true;
}

bool ShouldRemove(ll x1, ll y1, ll x2, ll y2){
  return ((double) x1) * y2 <= ((double)x2) * y1;
}

void Update(){
  while(true){
    ll x3, y3, l3, b3, s3;
    PopFromStack(x3, y3, l3, b3, s3);
    
    ll x2, y2, l2, b2, s2;
    if(!PopFromStack(x2, y2, l2, b2, s2)){
      Add(x3, l3, b3, s3);
      break;
    }

    if(y2 <= y3){
      l2 += l3;
      Add(x2, l2, b2, s2);
      continue;
    }

    ll x1, y1, l1, b1, s1;
    if(!PopFromStack(x1, y1, l1, b1, s1)){
      Add(x2, l2, b2, s2);
      Add(x3, l3, b3, s3);
      break;
    }

    if(ShouldRemove(x3 - x2, y3 - y2, x1 - x2, y1 - y2)){
      Add(x1, l1 + l2, b1, s1);
      Add(x3, l3, b3, s3);
    }
    else{
      Add(x1, l1, b1, s1);
      Add(x2, l2, b2, s2);
      Add(x3, l3, b3, s3);
      break;
    }
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(n);

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      scanf("%d", &n);
      Reset(n);
    }
    else if(t == 2){
      scanf("%d", &n);
      Add(X.top() + L.top(), n);
      Update();
    }
    else{
      int b, s;
      scanf("%d%d", &b, &s);
      bSum += b, sSum += s;
      Update();
    }

    printf("%lld %lld\n", X.top(), (bSum - B.top()) + (sSum - S.top()) * (X.top() - 1));
  }

  return 0;
}