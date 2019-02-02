#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int a[3];

int main(){
  int n, x, r;

  cin >> n >> x;
  a[x] = 1;

  for(r = n % 2, n %= 12; n > 0; n--, r = 1 - r)
    if(r == 1)
      swap(a[0], a[1]);
    else
      swap(a[1], a[2]);

  for(int i = 0; i < 3; i++)
    if(a[i])
      cout << i << '\n';

  return 0;
}
