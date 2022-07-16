#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define M (2 * N)

bool is_prime[M];
int c[M];
ll s[M];

int main(){
  int n;
  scanf("%d", &n);

  int m = 0;
  ll total_sum = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    ++c[x], s[x] += x;
    m = max(m, x);
    total_sum += x;
  }

  for(int i = 1; i < M; ++i){
    is_prime[i] = true;
    c[i] += c[i - 1], s[i] += s[i - 1];
  }

  ll ans = LLONG_MAX;
  for(int i = 2; i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    ans = min(ans, total_sum - m + abs(m - i));

    ll ansx = 0;
    for(int x = 0, y = i; y < M; x += i, y += i){
      is_prime[y] = false;
      int z = (x + y) / 2;
      ansx += ((s[z] - s[x]) - 1ll * (c[z] - c[x]) * x) + (1ll * (c[y] - c[z]) * y - (s[y] - s[z]));
    }

    if(ansx != total_sum){
      ans = min(ans, ansx);
    }
  }

  printf("%lld\n", ans);

  return 0;
}