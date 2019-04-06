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
#define B 4
#define M 16

void Query(string &s){
  cout << s << '\n';
  fflush(stdout);
  cin >> s;
}

void Solve(){
  int n, m, f;

  cin >> n >> m >> f;
  m = n - m;

  string s;
  for(int i = 0, x = 0; i < n; x = 1 - x){
    for(int j = 0; i < n && j < M; ++i, ++j){
      s.push_back('0' + x);
    }
  }
  Query(s);

  vector<int> cnts;
  for(int i = 0, x = 0, j = 0; i < n; i += M, x = 1 - x){
    int cnt = 0;
    for( ; j < m && s[j] == '0' + x; ++j){
      ++cnt;
    }
    cnts.push_back(cnt);
  }

  vector<int> v(m);

  for(int k = B - 1; k > -1; --k){
    s.clear();
    for(int i = 0; i < n; ){
      for(int j = 0; i < n && j < M; ++i, ++j){
        s.push_back('0' + ((j & (1 << k)) > 0));
      }
    }
    Query(s);
    for(int i = 0; i < m; ++i){
      v[i] = 2 * v[i] + (s[i] - '0');
    }
  }

  vector<bool> isWorkerBroken(n, true);
  for(int i = 0, k = 0, j = 0; i < n; i += M, ++k){
    for(int x = cnts[k]; x > 0; --x, ++j){
      isWorkerBroken[i + v[j]] = false;
    }
  }

  for(int i = 0; i < n; ++i){
    if(isWorkerBroken[i]){
      cout << i << ' ';
    }
  }
  cout << '\n';
  fflush(stdout);

  cin >> n;
  if(n == -1){
    exit(0);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    Solve();
  }
  return 0;
}