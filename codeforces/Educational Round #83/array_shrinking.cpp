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

map< vector<int>, int > dp;

int DP(vector<int> &a){
  if(a.empty()){
    return 0;
  }

  auto it = dp.find(a);
  if(it != dp.end()){
    return it->second;
  }

  const int n = a.size();
  int m = INT_MAX;

  for(int x : a){
    m = min(m, x);
  }

  vector<int> a1, a2;

  int i = 0;
  for( ; i < a.size() && a[i] != m; ++i){
    a1.push_back(a[i]);
  }

  int c = 0;
  for( ; i < a.size() && a[i] == m; ++i, ++c);

  if(c % 2 == 0){
    c /= 2;
    while(c--){
      a1.push_back(m + 1);
    }
    for( ; i < a.size(); ++i){
      a1.push_back(a[i]);
    }

    return dp[a] = DP(a1);
  }

  for( ; i < a.size(); ++i){
    a2.push_back(a[i]);
  }
  reverse(a2.begin(), a2.end());

  c /= 2;
  for(int j = 1; j <= c; ++j){
    a2.push_back(m + 1);
  }

  int ans = a.size();
  for(int x = 0; x <= c; ++x){
    if(x){
      a1.push_back(m + 1);
      a2.pop_back();
    }
    ans = min(ans, 1 + DP(a1) + DP(a2));
  }

  return dp[a] = ans;
}

int main(){
  int n;
  vector<int> a;

  cin >> n;
  while(n--){
    int x;
    cin >> x;
    a.push_back(x);
  }

  cout << DP(a) << '\n';

  return 0;
}