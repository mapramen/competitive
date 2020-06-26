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
#define N 1000001

int f[N];
string s;

int ComputeFailure(int i, char c){
  for( ; i != 0 && s[i] != c; i = f[i]);
  return i + (s[i] == c);
}

int main(){
  string t;

  cin >> t >> s;

  int n = s.size(), m = t.size();
  
  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  int ans = 0;
  for(int i = 0, x = 0; i < m; ++i){
    x = ComputeFailure(x, t[i]);
    if(x == n){
      ++ans;
      x = f[x];
    }
  }

  printf("%d\n", ans);
  
  return 0;
}