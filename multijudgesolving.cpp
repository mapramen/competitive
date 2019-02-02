#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int a[N];

int main(){
  int n, k, ans = 0;

  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a + 1, a + n + 1);

  for(int i = 1; i <= n; i++){
    while(a[i] > 2 * k){
      k *= 2;
      ans++;
    }
    k = max(k, a[i]);
  }

  cout << ans << '\n';

  return 0;
}
