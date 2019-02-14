#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int a[N], b[N], nxt[N];

int main(){
  int n;
  ll c = 0;
  double s = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i < N; ++i)
    b[i] = n + 1;

  for(int i = n; i > 0; --i){
    nxt[i] = b[a[i]];
    b[a[i]] = i;
    c += (nxt[i] - i);
  }

  s = c;
  for(int i = 1; i <= n; ++i){
    c += (i - nxt[i]);
    s += c;
  }

  s -= n;
  s *= 2;
  s += n;

  s /= n;
  s /= n;

  printf("%.15lf\n", s);

  return 0;
}
