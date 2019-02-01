#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;

  cin >> n;

  if(n % 10 < 5)
    cout << n - n % 5 << '\n';
  else
    cout << 10 * (n / 10 + 1) << '\n';

  return 0;
}
