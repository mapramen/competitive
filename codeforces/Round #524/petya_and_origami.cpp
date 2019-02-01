#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Ceil(int n, int k){
  return (n + k - 1) / k;
}

int main(){
  int n, k;

  cin >> n >> k;

  int ans = Ceil(2 * n, k) + Ceil(5 * n, k) + Ceil(8 * n, k);

  cout << ans << '\n';

  return 0;
}
