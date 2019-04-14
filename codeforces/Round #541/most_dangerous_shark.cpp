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
#define pil pair< int, ll >
#define N 10000005

int a[N], l[N], r[N];
ll c[N], ans = 0;
stack< pil > A;
deque< pil > B, C;

int TakeInputAndInitialise(){
  int n, m;
  vector< vector<int> > u(1), v(1);

  scanf("%d%d", &n, &m);

  while(n--){
    int k;
    scanf("%d", &k);
    vector<int> a, b;
    
    for(int i = 0; i < k; ++i){
      int x;
      scanf("%d", &x);
      a.push_back(x);
    }

    for(int i = 0; i < k; ++i){
      int x;
      scanf("%d", &x);
      b.push_back(x);
    }

    u.push_back(a);
    v.push_back(b);
  }

  int q, i = 1;
  scanf("%d", &q);
  while(q--){
    int id, mul;
    scanf("%d%d", &id, &mul);
    vector<int> &x = u[id], &y = v[id];
    for(int j = 0, k = x.size(); j < k; ++j, ++i){
      a[i] = x[j];
      c[i] = 1ll * mul * y[j];
    }
  }

  return m;
}

void PreProcess(int n){
  stack< pii > S;

  for(int i = 1; i <= n; ++i){
    int j = max(1, i - a[i] + 1);
    while(!S.empty() && j <= S.top().second){
      j = min(j, S.top().first);
      S.pop();
    }
    l[i] = j;
    S.push(make_pair(j, i));
  }

  while(!S.empty()){
    S.pop();
  }

  for(int i = n; i > 0; --i){
    int j = min(n, i + a[i] - 1);
    while(!S.empty() && S.top().first <= j){
      j = max(j, S.top().second);
      S.pop();
    }
    r[i] = j;
    S.push(make_pair(i, j));
  }

  while(!S.empty()){
    S.pop();
  }
}

ll QueryLeft(int i){
  int j = l[i] - 1;
  ll x = LLONG_MAX;
  while(!A.empty() && j <= A.top().first){
    x = min(x, A.top().second);
    A.pop();
  }
  A.push(make_pair(j, x));
  return x + c[i];
}

ll QueryRight(int i){
  while(!B.empty() && B.front().first < i){
    B.pop_front();
  }

  if(!B.empty()){
    return B.front().second;
  }

  while(!C.empty() && C.front().first < i){
    C.pop_front();
  }

  return C.front().second;
}

void UpdateLeft(int i){
  A.push(make_pair(i, ans));
}

void UpdateRight(int i){
  int j = r[i + 1];
  ll x = ans + c[i + 1];

  while(!C.empty() && C.front().first < j){
    B.push_back(C.front());
    C.pop_front();
  }
  
  while(!B.empty() && j <= B.back().first){
    C.push_front(B.back());
    B.pop_back();
  }

  while(!B.empty() && x < B.back().second){
    B.pop_back();
  }

  while(!C.empty() && C.front().first == j){
    x = min(x, C.front().second);
    C.pop_front();
  }

  B.push_back(make_pair(j, x));
}

int main(){
  int n = TakeInputAndInitialise();
  PreProcess(n);

  UpdateLeft(0);
  UpdateRight(0);

  for(int i = 1; i <= n; ++i){
    ans = min(QueryLeft(i), QueryRight(i));
    UpdateLeft(i);
    UpdateRight(i);
  }

  printf("%lld\n", ans);

  return 0;
}