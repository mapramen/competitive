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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

string s;
int a[N];
vector<int> charStart[N][2];
ll dp[N][N][N][2];

ll Compute(int l, int r);
ll ComputeX(int l, int r, int cnt, int bit);

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      if(s[i - 1] != s[j - 1]){
        continue;
      }
      char c = s[i - 1];
      charStart[i][c - '0'].push_back(j);
    }
  }
}

ll Compute(int l, int r){
  if(r < l){
    return 0ll;
  }
  
  ll &ans = dp[l][r][0][0];

  if(ans){
    return ans;
  }

  for(int bit = 0; bit < 2; ++bit){
    vector<int> &v = charStart[l][bit];
    int m = v.size();
    for(int cnt = 1; cnt <= m && v[cnt - 1] <= r; ++cnt){
      for(int k = cnt - 1; k < m && v[k] <= r; ++k){
        ans = max(ans, ComputeX(l, v[k], cnt, bit) + a[cnt] + Compute(v[k] + 1, r));
      }
    }
  }

  return ans;
}

ll ComputeX(int l, int r, int cnt, int bit){
  if(r < l){
    return 0ll;
  }
  
  ll &ans = dp[l][r][cnt][bit];

  if(ans){
    return ans;
  }

  if(cnt == 1){
    ans = Compute(l, r - 1);
    return ans;
  }

  vector<int> &v = charStart[l][bit];
  int m = v.size();

  for(int k = cnt - 2; k < m && v[k] < r; ++k){
    ans = max(ans, ComputeX(l, v[k], cnt - 1, bit) + Compute(v[k] + 1, r - 1));
  }

  return ans;
}

int main(){
  int n;
  cin >> n >> s;

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  PreProcess(n);

  ll ans = Compute(1, n);

  cout << ans << '\n';

  return 0;
}