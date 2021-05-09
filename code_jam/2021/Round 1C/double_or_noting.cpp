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

const int inf = 1e9;

string SanitizeString(string s){
  reverse(s.begin(), s.end());
  while(s.size() > 1 && s.back() == '0'){
    s.pop_back();
  }
  reverse(s.begin(), s.end());
  return s;
}

string GetNotString(string s){
  for(int i = s.size() - 1; i > -1; --i){
    s[i] = s[i] == '0' ? '1' : '0';
  }
  return SanitizeString(s);
}

int GetZeroStringAns(string s){
  int ans = 0;
  while(s != "0"){
    s = GetNotString(s);
    ++ans;
  }
  return ans;
}

int GetCharacteristicCount(string &s){
  int ans = 0, n = s.size();
  for(int i = 0, j = 0; i < n; i = j){
    for( ; j < n && s[j] == s[i]; ++j);
    ++ans;
  }
  return ans;
}

int GetNonReusableAns(string s, string t){
  int ans = t.size();

  if(s.back() == '0'){
    s = GetNotString(s);
    ++ans;
  }

  int sc = GetCharacteristicCount(s), tc = GetCharacteristicCount(t);

  return (sc < tc - 1) ? inf : sc + ans;
}

bool StartsWith(string &s, string &t){
  if(s.size() < t.size()){
    return false;
  }

  for(int i = 0, j = 0, m = t.size(); j < m; ++i, ++j){
    if(s[i] != t[j]){
      return false;
    }
  }

  return true;
}

int GetZCount(string s, string sprime, string t){
  if(sprime == t){
    return 0;
  }

  if(!StartsWith(t, sprime)){
    return inf;
  }

  int l = sprime.size();
  int a = s.back() - '0', b = t[l - 1] - '0', c = t[l] - '0';

  string tSuffix = string(t, l);

  return (a ^ b ^ c) + GetCharacteristicCount(tSuffix) - 1;
}

int GetReusableAns(string s, string t){
  int ans = inf, sc = GetCharacteristicCount(s);
  string sprime = s;

  for(int x = 0; x <= sc; ++x, sprime = GetNotString(sprime)){
    int z = GetZCount(s, sprime, t);
    if(x < z){
      continue;
    }
    int ansx = x + t.size() - sprime.size();
    ans = min(ans, ansx);
  }

  return ans;
}

int Solve(){
  string s, t;
  cin >> s >> t;

  if(t == "0"){
    return GetZeroStringAns(s);
  }

  int ans = 0;
  if(s == "0"){
    s = "1";
    ans = 1;
  }

  ans += min(GetNonReusableAns(s, t), GetReusableAns(s, t));
  return min(inf, ans);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    int ans = Solve();
    printf("Case #%d: %s\n", k, ans == inf ? "IMPOSSIBLE" : to_string(ans).c_str());
  }
  return 0;
}