#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, i, a, b;

  cin >> n;

  for(i = 1; i * i <= n; i++)
    if(n % i == 0)
      a = i, b = n / i;

  cout << a << ' ' << b << '\n';

  return 0;
}
