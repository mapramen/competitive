#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N];

int main(){
  int n, x, ans = 0;

  cin >> n >> x;

  for(int i = 1; i <= n; ++i){
    int j;
    cin >> j;
    ++a[j];
  }

  for(int i = 0; i < x; ++i)
    ans += (a[i] == 0);

  ans += a[x];

  cout << ans << '\n';

  return 0;
}
