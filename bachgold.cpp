#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans;

  cin >> n;

  ans = n / 2;

  cout << ans << '\n';

  for(int i = 1; i < ans; i++)
    cout << "2 ";

  cout << 2 + n % 2 << '\n';

  return 0;
}
