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
#define B 26

int dp[B];

void UpdateState(char c, int x){
  int k = c - 'a';
  dp[k] = (x + (dp[k] > 0));
}

int main(){
  int t, ans = 0;
  string s;

  cin >> t;
  
  while(t--){
    cin >> s;

    char startChar = s.front(), endChar = s.back();
    int n = s.size(), startCharLength = 0, endCharLength = 0;

    for(int i = 0; i < n && s[i] == startChar; ++i, ++startCharLength);
    for(int i = n - 1; i > -1 && s[i] == endChar; --i, ++endCharLength);

    for(int i = 0; i < B; ++i){
      char c = 'a' + i;
      if(c == startChar || c == endChar){
        continue;
      }
      UpdateState(c, 0);
    }

    if(startCharLength == n){
      int k = startChar - 'a';
      dp[k] += (dp[k] + 1) * n;
    }
    else{
      if(startChar == endChar){
        UpdateState(startChar, startCharLength + endCharLength);
      }
      else{
        UpdateState(startChar, startCharLength);
        UpdateState(endChar, endCharLength);
      }
    }

    for(int i = 0; i < n; ){
      int j;
      for(j = i; j < n && s[j] == s[i]; ++j);
      int k = s[i] - 'a';
      dp[k] = max(dp[k], j - i);
      i = j;
    }
  }

  for(int i = 0, n = s.size(); i < n; ){
    int j;
    for(j = i; j < n && s[j] == s[i]; ++j);
    ans = max(ans, j - i);
    i = j;
  }

  for(int i = 0; i < B; ++i){
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
  
  return 0;
}