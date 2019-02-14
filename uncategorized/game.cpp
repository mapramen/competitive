#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 18
#define N (1 << B)

int a[N];

int main(){
  int n, r, m;
  double s = 0;

  scanf("%d%d", &n, &r);

  m = (1 << n);
  for(int i = 0; i < m; ++i){
    scanf("%d", &a[i]);
    s += a[i];
  }

  printf("%.15lf\n", s / m);

  while(r--){
    int i, x;
    scanf("%d%d", &i, &x);
    x -= a[i];
    s += x;
    a[i] += x;
    printf("%.15lf\n", s / m);
  }

  return 0;
}
