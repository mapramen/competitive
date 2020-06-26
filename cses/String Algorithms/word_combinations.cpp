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
#define N 5001
#define M 1000001
#define B 26
#define MOD 1000000007

int dp[N], T[B][M], nxt;
bool isWordEnd[M];

void AddToTrie(string s){
  if(s.size() >= N){
    return;
  }

  reverse(s.begin(), s.end());

  int i = 0;
  for(auto c: s){
    int k = c - 'a';
    if(T[k][i] == 0){
      T[k][i] = ++nxt;
    }
    i = T[k][i];
  }

  isWordEnd[i] = true;
}

int GetNextIndex(int i, char c){
  return T[c - 'a'][i];
}

int main(){
  int n, m;
  string s;

  cin >> s >> m;

  n = s.size();
  while(m--){
    string t;
    cin >> t;
    AddToTrie(t);
  }

  dp[0] = 1;
  for(int i = 1; i <= n; ++i){
    int ans = 0;
    for(int j = i - 1, x = 0; j > -1; --j){
      x = GetNextIndex(x, s[j]);
      if(x == 0){
        break;
      }
      if(isWordEnd[x]){
        ans = (ans + dp[j]) % MOD;
      }
    }
    dp[i] = ans;
  }

  printf("%d\n", dp[n]);

  return 0;
}