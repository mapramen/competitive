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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 998244353

int main(){
  int n;
  string s;

  cin >> n >> s;

  int x = 0, y = 0;
  for(int i = 0; i < n && s[i] == s[0]; ++i, ++x);
  for(int i = n - 1; i > -1 && s[i] == s[n - 1]; --i, ++y);

  ll ans;
  if(s.front() != s.back()){
    ans = 1 + x + y;
  }
  else{
    ans = 1ll * (x + 1) * (y + 1);
  }

  ans %= MOD;

  cout << ans << '\n';
  
  return 0;
}