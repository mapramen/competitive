#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int p[N];
ll s[N];

ll Query(int n, int x){
  int i = upper_bound(p + 1, p + n + 1, x) - p;
  return s[i - 1];
}

ll Query(int n, int l, int r){
  return Query(n, r) - Query(n, l - 1);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }
  sort(p + 1, p + n + 1);

  for(int i = 1; i <= n; ++i){
    s[i] = s[i - 1] + p[i];
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", Query(n, l, r));
  }

  return 0;
}