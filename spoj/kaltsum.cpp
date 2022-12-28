#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define BLOCK_SIZE 320

ll a[N], s[N], T[BLOCK_SIZE][N];

ll Sum(int n, int l, int r){
  return s[min(n, r)] - s[max(0, l - 1)];
}

ll KAlternateSum(int n, int k, int i){
  return i > n ? 0 : T[k][i];
}

ll QuerySmallBlock(int n, int k, int i, int j){
  ll ans = T[k][i];
  if(j < n){
    int p = (j - i + 1) / k;
    ans += p % 2 == 1 ? T[k][j + 1] : -T[k][j + 1];
  }
  return ans;
}

ll QueryLargeBlock(int n, int k, int i, int j){
  ll ans = 0;
  for(int mul = 1; i <= j; i += k, mul *= -1){
    ans += mul * (s[i + k - 1] - s[i - 1]);
  }
  return ans;
}

ll Query(int n, int k, int i, int j){
  return k < BLOCK_SIZE ? QuerySmallBlock(n, k, i, j) : QueryLargeBlock(n, k, i, j);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    s[i] = s[i - 1] + a[i];
  }

  for(int k = 1; k < BLOCK_SIZE; ++k){
    for(int i = n; i != 0; --i){
      T[k][i] = Sum(n, i, i + k - 1) - KAlternateSum(n, k, i + k);
    }
  }

  while(q--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    printf("%lld\n", Query(n, k, i, j));
  }

  return 0;
}