#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10000005

ll c[N];

int main(){
  int n, k, i, j, ans;
  ll s = 0;

  scanf("%d%d", &n, &k);

  for(j = 0; j < n; j++){
    scanf("%d", &i);
    c[i]++;
    s += i;
  }

  if(s < k){
    printf("-1\n");
    return 0;
  }

  for(i = 1, j = N - 1, s = n, ans = 1; i <= j; j--){
    int x = (j + 1) / 2, y = j - x;
    ll cnt = c[j];
    c[j] -= cnt;

    if(y < i)
      break;

    s += cnt;
    c[x] += cnt, c[y] += cnt;

    for( ; i < N && s - c[i] >= k; i++)
      s -= c[i];

    ans = i;
  }

  cout << ans << '\n';

  return 0;
}
