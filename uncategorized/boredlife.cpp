#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int a, b, n, ans = 1;
  cin >> a >> b;
  n = min(a, b);
  for(int i = 1; i <= n; i++)
    ans *= i;
  cout << ans << '\n';
  return 0;
}
