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
#define tiiii tuple< int, int, int, int >
#define N 200001

int a[N];
vector<int> v;
deque< tiiii > Q;

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  Q.push_back(make_tuple(m, 1, a[1] - m, a[1] - 1));
  Q.push_back(make_tuple(1, m, a[n] + 1, a[n] + m));
  for(int i = 1; i < n; ++i){
    Q.push_back(make_tuple(1, 1, a[i] + 1, a[i + 1] - 1));
  }

  ll ans = 0;
  while(v.size() < m){
    int d1, d2, l, r;
    tie(d1, d2, l, r) = Q.front();
    Q.pop_front();

    if(l > r){
      continue;
    }

    int d = min(d1, d2);

    if(d1 <= d2){
      v.push_back(l);
      ++d1, ++l;
    }
    else{
      v.push_back(r);
      ++d2, --r;
    }

    tiiii t = make_tuple(d1, d2, l, r);
    if(min(d1, d2) == d){
      Q.push_front(t);
    }
    else{
      Q.push_back(t);
    }
    
    ans += d;
  }

  printf("%lld\n", ans);
  for(int x : v){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}