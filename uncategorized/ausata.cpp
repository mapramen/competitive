#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

ll s[N];

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%lld", &s[i]);

  for(int i = 1; i <= n; ++i)
    s[i] += s[i - 1];

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", (s[r] - s[l - 1]) / (r - l + 1));
  }

  return 0;
}
