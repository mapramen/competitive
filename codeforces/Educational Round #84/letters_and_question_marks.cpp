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
#define pil pair<int,ll>
#define N 1001
#define B 14
#define M (1 << B)

vector< vector<int> > v(B + 1);
int go[N][B], fail[N], weight[N], nxt, maxLength;
ll dp[N][M];
const ll negativeInfinity = LLONG_MIN / 2;

void AddStringToAhoCorasick(string s, int val){
  int i = 0;
  for(auto c : s){
    int k = c - 'a';
    if(go[i][k] == 0){
      go[i][k] = ++nxt;
    }
    i = go[i][k];
  }
  maxLength = max(maxLength, (int)s.size());
  weight[i] += val;
}

void BuildAhoCorasick(){
  queue<int> Q;

  for(int x = 0; x < B; ++x){
    if(go[0][x]){
      Q.push(go[0][x]);
    }
  }

  while(!Q.empty()){
    const int i = Q.front();
    Q.pop();

    weight[i] += weight[fail[i]];

    for(int x = 0; x < B; ++x){
      const int j = go[i][x];
      if(j){
        fail[j] = go[fail[i]][x];
        Q.push(j);
      }
      else{
        go[i][x] = go[fail[i]][x];
      }
    }
  }
}

inline pil GetTransitionedNode(int i, const string &s){
  ll val = 0;
  for(auto c : s){
    i = go[i][c - 'a'];
    val += weight[i];
  }
  return make_pair(i, val);
}

void ApplyStringTransitions(const string &s, const int n, const int qCount){
  for(int i = 0; i <= n; ++i){
    int j;
    ll val;
    tie(j, val) = GetTransitionedNode(i, s);

    for(int mask : v[qCount]){
      if(dp[i][mask] < negativeInfinity){
        continue;
      }

      val += dp[i][mask];

      for(int x = 0; x < B; ++x){
        if((mask & (1 << x)) > 0){
          continue;
        }

        const int k = go[j][x], nmask = mask | (1 << x);
        dp[k][nmask] = max(dp[k][nmask], val + weight[k]);
      }

      val -= dp[i][mask];
    }
  }
}

int Initialise(){
  int n;

  cin >> n;
  while(n--){
    string s;
    int val;
    cin >> s >> val;
    AddStringToAhoCorasick(s, val);
  }

  BuildAhoCorasick();

  for(int mask = 0; mask < M; ++mask){
    v[__builtin_popcount(mask)].push_back(mask);
  }

  return nxt;
}

int main(){
  int n = Initialise();

  string t;
  cin >> t;

  int cur = 0;

  for(int i = 0; i <= n; ++i){
    for(int mask = 0; mask < M; ++mask){
      dp[i][mask] = LLONG_MIN;
    }
  }

  dp[0][0] = 0;

  string s;
  int qCount = 0;
  for(auto c : t){
    if(c != '?'){
      s.push_back(c);
      continue;
    }
    ApplyStringTransitions(s, n, qCount);
    s.clear();
    ++qCount;
  }

  ll ans = LLONG_MIN;
  for(int i = 0; i <= n; ++i){
    int j;
    ll val;
    tie(j, val) = GetTransitionedNode(i, s);

    for(int mask : v[qCount]){
      if(dp[i][mask] < negativeInfinity){
        continue;
      }
      ans = max(ans, val + dp[i][mask]);
    }
  }

  cout << ans << '\n';

  return 0;
}