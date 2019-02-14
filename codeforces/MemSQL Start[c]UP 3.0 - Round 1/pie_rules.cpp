#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 55

int a[N], s[N], dp[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  for(int i = n; i > 0; --i)
    s[i] = a[i] + s[i + 1];

  for(int i = n; i > 0; --i)
    dp[i] = max(a[i] + s[i + 1] - dp[i + 1], dp[i + 1]);

  cout << s[1] - dp[1] << ' ' << dp[1] << '\n';

  return 0;
}
