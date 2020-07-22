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
#define tiii tuple<int,int,int>
#define N 100001
#define M 101

int h[N], s[N], k[N], dp[N];
vector<ll> A, B;
deque<int> Q;

void SlidingMaximum(int k){
  int n = A.size();
  B.resize(n);

  while(!Q.empty()){
    Q.pop_back();
  }

  for(int i = 0; i < n; ++i){
    while(!Q.empty() && i - Q.front() > k){
      Q.pop_front();
    }

    while(!Q.empty() && A[Q.back()] <= A[i]){
      Q.pop_back();
    }

    Q.push_back(i);
    B[i] = A[Q.front()];
  }
}

void RelaxBookType(int n, int w, int c, int k){
  for(int r = 0; r <= n && r < w; ++r){
    for(int i = r, j = 0; i <= n; i += w, ++j){
      A.push_back(dp[i] - j * c);
    }
    
    SlidingMaximum(k);
    for(int i = r, j = 0; i <= n; i += w, ++j){
      dp[i] = j * c + B[j];
    }

    A.clear(), B.clear();
  }
}

int main(){
  int n, m;

  cin >> m >> n;

  for(int i = 1; i <= m; ++i){
    cin >> h[i];
  }

  for(int i = 1; i <= m; ++i){
    cin >> s[i];
  }

  for(int i = 1; i <= m; ++i){
    cin >> k[i];
  }

  for(int i = 1; i <= m; ++i){
    RelaxBookType(n, h[i], s[i], k[i]);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';

  return 0;
}