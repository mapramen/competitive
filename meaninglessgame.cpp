#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int leastPrimeDivisor[N];

void Initialize(){
  for(int i = 2; i < N; i++)
    for(int j = i; j < N; j += i)
      if(leastPrimeDivisor[j] == 0)
        leastPrimeDivisor[j] = i;
}

ll CubeRoot(ll n){
  ll x = cbrt(n) - 1;
  while(x * x * x < n)
    ++x;
  if(x * x * x != n)
    x = -1;
  return x;
}

int main(){
  Initialize();
  int q;
  scanf("%d", &q);
  while(q--){
    ll a, b, c;
    bool ans = 1;

    scanf("%lld%lld", &a, &b);
    c = CubeRoot(a * b);

    if(c != -1){
      while(c != 1 && ans == 1){
        int d = leastPrimeDivisor[c], n = 0, n1 = 0, n2 = 0, x, y;
        while(c % d == 0)
          n++, c /= d;

        while(a % d == 0)
          n1++, a /= d;

        while(b % d == 0)
          n2++, b /= d;

        x = (2 * n1 - n2) / 3, y = (2 * n2 - n1) / 3;
        ans = (x >= 0 && y >= 0 && (x + y == n) && (2 * x + y == n1) && (x + 2 * y == n2));
      }

      if(ans)
        ans = (a == 1 && b == 1);
    }
    else
      ans = 0;

    if(ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
