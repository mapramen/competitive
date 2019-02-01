#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 61

ll b, dp[N], inf = 1E18;

void CheckAndUpdate(int k, ll x, ll y){
  if(x <= inf / b)
    dp[k] = min(dp[k], b * x + y);
}

int main(){
  ll n;
  string s;

  cin >> b >> s;
  n = s.size();

  for(int i = 1; i <= n; i++)
    dp[i] = inf + 1;

  for(int i = 0; i < n; i++){
    if(s[i] == '0'){
      CheckAndUpdate(i + 1, dp[i], 0ll);
    }
    else{
      ll y = 0;
      for(int j = i + 1; j <= n ; j++){
        y = 10 * y + (s[j - 1] - '0');
        if(y >= b)
          break;
        else
          CheckAndUpdate(j, dp[i], y);
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}
