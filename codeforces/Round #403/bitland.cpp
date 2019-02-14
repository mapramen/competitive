#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501
#define B 60

ll inf = 1E18;
bitset<N> dp[B][2][N], c[N], cx[N];

void MatMul(int n, bitset<N> a[N], bitset<N> b[N], bitset<N> c[N]){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(a[i].test(j))
        c[i] |= b[j];
    }
  }
}

void PreProcess(int n){
  for(int k = 1; k < B; k++)
    for(int j = 0; j < 2; j++)
      MatMul(n, dp[k - 1][j], dp[k - 1][1 - j], dp[k][j]);
}

int main(){
  int n, m;
  ll ans = 0;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j, t;
    scanf("%d%d%d", &i, &j, &t);
    dp[0][t][i].set(j);
  }

  PreProcess(n);

  for(int i = 1; i <= n; i++)
    c[i].set(i);

  for(int k = B - 1, j = 0; k > -1; k--){
    bool check = 0;

    MatMul(n, c, dp[k][j], cx);

    for(int i = 1; i <= n; i++)
      check |= cx[i].any();

    if(check){
      ans += (1ll << k);
      j = 1 - j;

      for(int i = 1; i <= n; i++)
        c[i] = cx[i];
    }

    for(int i = 1; i <= n; i++)
      cx[i].reset();
  }

  if(ans > inf)
    ans = -1;

  cout << ans << '\n';

  return 0;
}
