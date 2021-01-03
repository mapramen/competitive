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

string Inverse(string s){
  for(int n = s.size(), i = 0; i < n; ++i){
    if(s[i] != '?'){
      s[i] = '0' + (1 - (s[i] - '0'));
    }
  }
  return s;
}

ll GetBaseAns(string &s, int x, int y){
  ll ans = 0;
  int zero = 0, one = 0;
  for(char c: s){
    if(c == '0'){
      ans += 1ll * y * one;
      ++zero;
    }
    else{
      ans += 1ll * x * zero;
      ++one;
    }
  }
  return ans;
}

ll GetAns(string &s, int x, int y){
  ll ans = GetBaseAns(s, x, y);

  int n = s.size(), zero = 0, one = 0;
  for(char c: s){
    one += (c != '0');
  }

  ll ansx = ans;
  for(int i = 1, j = n - 1; i <= n; ++i, --j){
    char c = s[i - 1];
    zero += (c == '0');
    one -= (c == '1');

    if(c != '?'){
      continue;
    }

    ansx -= 1ll * x * zero;
    ansx -= 1ll * y * (j - one + 1);

    ansx += 1ll * y * (i - 1 - zero);
    ansx += 1ll * x * (one - 1);

    ++zero;
    --one;

    ans = min(ans, ansx);
  }

  return ans;
}

int main(){
  string s;
  int x, y;

  cin >> s >> x >> y;
  
  string t = Inverse(s);
  
  ll ans = min(GetAns(s, x, y), GetAns(t, y, x));

  cout << ans << '\n';

  return 0;
}