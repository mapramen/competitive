#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 102

int a[N], b[N], c[N];

int main(){
  int n, ans = 0;

  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  for(int i = 1; i <= n; ++i)
    b[i] = b[i - 1] + (a[i] == 0);

  for(int i = n; i > 0; --i)
    c[i] = c[i + 1] + (a[i] == 1);

  for(int i = 1; i <= n + 1; ++i)
    ans = max(ans, b[i - 1] + c[i]);

  cout << ans << '\n';

  return 0;
}
