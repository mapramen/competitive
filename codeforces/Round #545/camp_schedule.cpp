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
#define N 500001

int f[N], c[2];
string ans;

int PreProcess(string s){
  int n = s.size(), k = 0;
  for(int i = 2; i <= n; ++i){
    for( ; k > 0 && s[k] != s[i - 1]; k = f[k]);
    k += (s[k] == s[i - 1]);
    f[i] = k;
  }
  return k;
}

bool AppendStringToAns(string &s){
  for(char x : s){
    int j = x - '0';
    if(c[j] == 0){
      return false;
    }
    ans.push_back(x);
    --c[j];
  }
  return true;
}

int main(){
  string s, t;
  cin >> s >> t;
  int n = t.size(), m = PreProcess(t);

  for(int i = 0; i < s.size(); ++i){
    ++c[s[i] - '0'];
  }

  s = string(t, m);

  if(AppendStringToAns(t)){
    while(AppendStringToAns(s));
  }

  for(int i = 0; i < 2; ++i){
    int k = c[i];
    while(k--){
      ans.push_back('0' + i);
    }
  }

  cout << ans << '\n';

  return 0;
}