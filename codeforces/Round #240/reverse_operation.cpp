#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 20
#define N 1 << B

int a[N], b[N];
ll I[B + 1], revI[B + 1];

int main(){
  int n, q;
  ll ans;

  scanf("%d", &n);

  for(int i = 0; i < (1 << n); i++)
    scanf("%d", &a[i]);

  for(int x = 1; x <= n; ++x){
    int l = 1 << x;
    for(int i = 0; i < (1 << n); i += l){
      int m = l >> 1, i1 = i, j1 = i + m, i2 = j1, j2 = i2 + m, i3 = i2, k;
      for(k = i; i1 < j1; ++i1){
        for( ; i2 < j2 && a[i2] < a[i1]; b[k++] = a[i2], ++i2);
        for(i3 = max(i2, i3); i3 < j2 && a[i3] <= a[i1]; ++i3);
        b[k++] = a[i1];
        I[x] += (i2 - j1);
        revI[x] += (j2 - i3);
      }
      for( ; i2 < j2; b[k++] = a[i2], ++i2);
      for(k = i; k < j2; a[k] = b[k], ++k);
    }
  }

  scanf("%d", &q);

  while(q--){
    int i;
    scanf("%d", &i);

    for(int j = 0; j <= i; j++)
      swap(I[j], revI[j]);

    for(i = 0, ans = 0; i <= n; i++)
      ans += I[i];

    printf("%lld\n", ans);
  }

	return 0;
}
