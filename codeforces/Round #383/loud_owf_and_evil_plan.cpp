#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int crush[N], indegree[N];

int main(){
  int n, i, j, k, totalcycles = 0, x;
  ll ans = 1;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    scanf("%d", &j);
    crush[i] = j;
    indegree[j]++;
  }

  for(i = 1; i <= n && indegree[i] > 0; i++);

  if(i <= n){
    printf("-1\n");
    return 0;
  }

  for(i = 1; i <= n; i++){
    if(crush[i] == 0)
      continue;

    for(j = i, k = 0; crush[j] != 0; k++){
      x = crush[j];
      crush[j] = 0;
      j = x;
    }

    if(k % 2 == 0)
      k /= 2;

    ans = ans * (k / __gcd(ans, 1ll * k));
  }

  printf("%lld\n", ans);

  return 0;
}
