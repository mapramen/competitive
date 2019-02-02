#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, s = 0, y = 0;

  cin >> n >> m;

  for(int i = 1; i <= n; ++i){
    int a;
    cin >> a;
    s += a;
    y = max(y, a);
  }

  int a = y, b = y + m;

  for( ; s + m > a * n; ++a);

  cout << a << ' ' << b << '\n';

  return 0;
}
