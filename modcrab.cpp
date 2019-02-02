#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define inf INT_MAX / 2

int Fun(int n, int h1, int a1, int c1, int h2, int a2){
  h1 += n * (c1 - a2);
  int m = 0;
  for(m = 1; h1 > 0 && h2 > 0; ++m){
    if(m % 2 == 1)
      h2 -= a1;
    else
      h1 -= a2;
  }
  m = (m + 1) / 2;
  if(h1 > 0)
    m += n;
  else
    m = inf;
  return m;
}

int main(){
  int h1, a1, c1, h2, a2;
  pii ans = MP(inf, 0);

  cin >> h1 >> a1 >> c1 >> h2 >> a2;

  for(int i = 0; i <= 100000; ++i)
    ans = min(ans, MP(Fun(i, h1, a1, c1, h2, a2), i));

  int n, m;
  tie(n, m) = ans;

  printf("%d\n", n);

  n -= m;

  for(int i = 1; i <= m; ++i)
    printf("HEAL\n");

  for(int i = 1; i <= n; ++i)
    printf("STRIKE\n");

  return 0;
}
