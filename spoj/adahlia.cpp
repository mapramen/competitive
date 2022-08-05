#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 40000001
#define K 8
#define M (1 << K)

ll A[N], B[N];
int cnt[M], start_index[M];

void Sort(int n){
  int a = K, b = 0;
  for(int iter = 0; iter < 8; ++iter, a += K, b += K){
    ll mask = (1ll << a) - (1ll << b);

    for(int i = 1; i <= n; ++i){
      ++cnt[((A[i] & mask) >> b)];
    }

    for(int j = 1; j < M; ++j){
      start_index[j] = start_index[j - 1] + cnt[j - 1];
    }

    for(int i = n; i != 0; --i){
      int j = (A[i] & mask) >> b;
      B[start_index[j] + cnt[j]--] = A[i];
    }

    memcpy(A, B, N * sizeof(ll));
  }
}

int main(){
  int n;
  ll x, a, b, c;

  scanf("%d%lld%lld%lld%lld", &n, &a, &b, &c, &A[1]);

  for(int i = 2; i <= n; ++i){
    __int128 z = 1;
    A[i] = (a * z * A[i - 1] + b) % c;
  }

  Sort(n);

  ll ans = 0;
  for(int i = 2; i <= n; ++i){
    ans = max(ans, A[i] - A[i - 1]);
  }
  printf("%lld\n", ans);

  return 0;
}