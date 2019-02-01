#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, s = 0, k = 0;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    int a;
    cin >> a;
    k = max(k, a);
    s += a;
  }

  for( ; n * k <= 2 * s; ++k);

  cout << k << '\n';

  return 0;
}
