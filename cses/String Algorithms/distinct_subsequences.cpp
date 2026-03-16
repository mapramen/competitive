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
#define B 26
#define MOD 1000000007

int dp[B];

int main(){
  string s;
  cin >> s;

  int ans = 1;
  for(char c: s){
    int i = c - 'a';
    int ansx = (MOD + ans - dp[i]) % MOD;
    dp[i] = (dp[i] + ansx) % MOD;
    ans = (ans + ansx) % MOD;
  }

  cout << (MOD + ans - 1) % MOD << '\n';

  return 0;
}