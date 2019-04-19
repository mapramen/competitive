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
#define N 3001
#define M 5000000
#define MOD 1000000007

vector< vector<int> > statePath(N, vector<int>(1));
int T[M][2], dp[M], nxt, c[N];
set<string> forbiddenCodes{"0011", "0101", "1110", "1111"};
string S;

int GetNextState(int currentState, int transition){
  int nextState;
  if(T[currentState][transition] == 0){
    nextState = ++nxt;
    T[currentState][transition] = nextState;
    dp[nextState] = -1;
  }
  else{
    nextState = T[currentState][transition];
  }
  return nextState;
}

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    S.push_back('0' + x);
  }

  dp[0] = 1;
  for(int l = 1; l <= n; ++l){
    for(int i = 1, j = i + l - 1; i <= n - l + 1; ++i, ++j){
      int currentState = GetNextState(statePath[i].back(), S[j - 1] - '0');
      statePath[i].push_back(currentState);

      int &val = dp[currentState];

      if(val >= 0){
        continue;
      }

      val = 0;
      for(int k = 1; k <= 4 && j - k + 1 >= i; ++k){
        string s = string(S, j - k, k);
        if(forbiddenCodes.count(s)){
          continue;
        }
        val = (val + dp[statePath[i][l - k]]) % MOD;
      }

      c[j] = (c[j] + val) % MOD;
    }
  }
  
  for(int i = 1; i <= n; ++i){
    c[i] = (c[i] + c[i - 1]) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    cout << c[i] << '\n';
  }

  return 0;
}