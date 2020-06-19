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

vector<queue<int>> V(2);
int a[N], onGoing[N], z = 0;
ll t[2];
bool isBlocked[N];

void Initialise(int n){
  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end(), greater<pii>());

  for(pii p: v){
    V[0].push(p.second);
    V[1].push(p.second);
  }
  v.clear();
}

int GetIndex(){
  int x = t[0] == t[1] ? z : (t[0] > t[1]);
  z ^= 1;

  return x;
}

int main(){
  int n;

  scanf("%d", &n);
  Initialise(n);

  while(!V[0].empty() || !V[1].empty()){
    int x = GetIndex();

    isBlocked[onGoing[x]] = false;
    onGoing[x] = 0;

    if(V[x].empty()){
      continue;
    }

    if(isBlocked[V[x].front()]){
      if(V[x].size() == 1){
        t[x] = t[1 - x];
        continue;
      }
    }

    for( ; isBlocked[V[x].front()]; V[x].pop()){
      V[x].push(V[x].front());
    }

    int i = V[x].front();
    V[x].pop();

    t[x] += a[i];
    onGoing[x] = i;
    isBlocked[i] = true;
  }

  ll ans = max(t[0], t[1]);

  printf("%lld\n", ans);

  return 0;
}