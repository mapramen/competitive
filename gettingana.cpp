#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define M 5

int a[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  sort(a + 1, a + n + 1, greater<int>());

  int ans = 0;
  for(int i = 0, s = 0; i <= n; ++i){
    s += a[i];
    if(2 * (s + (n - i) * M) >= n * (2 * M - 1)){
      ans = n - i;
    }
  }

  cout << ans << '\n';

  return 0;
}
