#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll q[9], p[9];
char s[2];

int main(){
  ll n, i, j, k, x0, y0, x, y, d, m, check;

  scanf("%lld", &n);
  scanf("%lld%lld", &x0, &y0);

  for(ll m = 0; m < 9; m++)
    q[m] = 1E10;

  while(n--){
    scanf("%s", s);
    scanf("%lld%lld", &x, &y);

    i = x - x0, j = y - y0;

    if(abs(i) != abs(j) && i != 0 && j != 0)
      continue;

    d = max(abs(i), abs(j));
    i /= d, j /= d;

    i++, j++;
    m = 3 * i + j;

    if(s[0] == 'Q')
      k = 3;
    else
      k = (s[0] != 'R') + 1;

    if(d < q[m])
      q[m] = d, p[m] = k;
  }

  for(m = 0; m < 9; m++){
    i = m / 3, j = m % 3, check;
    i--, j--;

    if(i == 0 || j == 0)
      check = 0;
    else
      check = 1;

    if(q[m] != 1E10 && (p[m] & (1 << check))){
        cout << "YES\n";
        return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
