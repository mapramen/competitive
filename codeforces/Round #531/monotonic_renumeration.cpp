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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 998244353

int main(){
  int n;
  vector< pii > a, v;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a.push_back(make_pair(x, i));
  }

  sort(a.begin(), a.end());

  for(int i = 0; i < n; ++i){
    int j;
    for(j = i; j < n && a[j].first == a[i].first; ++j);
    --j;
    v.push_back(make_pair(a[i].second, a[j].second));
    i = j;
  }

  sort(v.begin(), v.end());

  int ans = 1;
  for(int i = 0; i < v.size(); ++i){
    int j, r = v[i].second;
    for(j = i; j < v.size() && v[j].first <= r; ++j){
      r = max(r, v[j].second);
    }
    ans = ((1 + (i > 0)) * ans) % MOD;
    i = j - 1;
  }

  printf("%d\n", ans);

  return 0;
}