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
#define B 20

int s[(1 << B)];
vector<int> c;

tuple<int,vector<int>,vector<int>> ReadInput(){
  int n, s;
  vector<int> v;

  cin >> n >> s;
  for(int x = 1; x <= n; ++x){
    int i;
    cin >> i;
    v.push_back(i);
  }

  return make_tuple(s, vector<int>(v.begin(), v.begin() + n / 2), vector<int>(v.begin() + n / 2, v.end()));
}

void Initialise(vector<int> &v, int m){
  const int n = v.size();
  
  for(int mask = 1; mask < (1 << n); ++mask){
    int k = __builtin_ctz(mask);
    s[mask] = min(m + 1, v[k] + s[(mask ^ (1 << k))]);
  }

  for(int mask = 0; mask < (1 << n); ++mask){
    if(s[mask] <= m){
      c.push_back(s[mask]);
    }
  }
  c.push_back(INT_MAX);
  sort(c.begin(), c.end());
}

int GetLECount(int x){
  return upper_bound(c.begin(), c.end(), x) - c.begin();
}

int GetCount(int x){
  return GetLECount(x) - GetLECount(x - 1);
}

ll Compute(vector<int> &v, int m){
  const int n = v.size();

  for(int mask = 1; mask < (1 << n); ++mask){
    int k = __builtin_ctz(mask);
    s[mask] = min(m + 1, v[k] + s[(mask ^ (1 << k))]);
  }

  ll ans = 0;
  for(int mask = 0; mask < (1 << n); ++mask){
    if(s[mask] > m){
      continue;
    }
    ans += GetCount(m - s[mask]);
  }

  return ans;
}

int main(){
  auto [m, v1, v2] = ReadInput();
  Initialise(v1, m);
  cout << Compute(v2, m) << '\n';
  return 0;
}